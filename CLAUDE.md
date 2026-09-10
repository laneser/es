# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## 專案概覽

這是「東方故事 MUD」的 mudlib（LPC 原始碼樹）。mudlib 自稱 `ES_Lib`（見 `include/config.h`），
源流是 TMI-2 mudlib 的中文化分支，大量檔案仍保留 1992–1995 年的 TMI 原始檔頭與作者註解。

這裡**沒有** build system、套件管理、linter 或測試框架。所有 `.c` 檔都是 LPC，
由驅動在執行期即時編譯；「部署」等於在遊戲內用 `update` 重新載入物件。

## 執行方式

驅動跑在 devcontainer 裡（**FluffOS v2026.0901.0**，自 source 建置）：

```bash
# 建立映像（第一次，約 3 分鐘）
docker build -t es-mud-fluffos:2026.0901 -f .devcontainer/Dockerfile .devcontainer

# 啟動 MUD
docker run -d --name es-mud -p 8888:8888 -v "$PWD":/mudlib -w /mudlib \
  es-mud-fluffos:2026.0901 driver /mudlib/etc/fluffos.cfg

docker logs -f es-mud     # 啟動與編譯錯誤
tail -f log/debug.log     # 同上，mudlib 端的錯誤處理器輸出
telnet localhost 8888     # 連進遊戲
docker rm -f es-mud       # 停止
```

VS Code 直接開 `.devcontainer/devcontainer.json` 也可以，工作目錄掛在 `/mudlib`。

- **設定檔是 `etc/fluffos.cfg`**，不是根目錄的 `config.cfg`。後者是 MudOS 0.9.20 / FluffOS 2017
  時代的舊格式，留著純供對照；`mudos.exe` 同理，是舊的 Windows 驅動執行檔，在現在的流程中用不到。
- `etc/fluffos.cfg` 裡標示「相容」的開關（`sane explode string`、`old type behavior`、
  `old range behavior`、`this_player in call_out` 等）是為了讓 1990 年代的 LPC 照原本語意運作。
  FluffOS 2019 以後把這些原本的編譯期 `#define` 改成執行期設定，**改動它們會改變既有程式的行為**。
- 管理員帳號 `admin`（另有 `mudren`），密碼 `12345`。
- `log/`、`tmp/`、`data/`（玩家與物件存檔）是執行期產物，不是原始碼。

### 遊戲內的開發迴圈

開發是在遊戲內進行的，命令都在 `/cmds/` 下、檔名為 `_<cmd>.c`：

- `update <file>`：重新編譯並載入單一物件；`update -r/-R` 連同 inherit 鏈深度更新
  （改 `/std/user.c` 這類基底檔時需要）。不帶參數時用玩家的 `cwf`（current working file）。
- `clone` / `dest` / `load` / `goto` / `at` / `eval`：實例化與檢視物件。
- `data` / `datatmp` / `sc` / `ss`：檢視物件的 `ob_data` / `tmp_ob_data`。

## 檔案編碼：UTF-8

整棵樹（原始碼、文件、設定）都是 **UTF-8**，內容為**繁體中文**。

這是從 GBK + 簡體中文一次性轉換過來的，轉換過程留下幾個要知道的痕跡：

- 少數檔案裡有 `□`（U+25A1）缺字，例如 `cmds/std/_look.c:406` 的「這□沒有任何明顯的出口」。
  這是更早的 Big5→GBK 轉換就已經遺失的字，**不是**現在這輪轉換造成的，需要人工逐一補回。
- `data/` 與各領域 `data/attic/` 下的舊留言板存檔有 16 個檔含 U+FFFD 替換字元，
  來源是原檔本身就有的壞位元組。那些是執行期資料，不影響遊戲程式。
- 中文字後面的殘留轉義反斜線（Big5 時代為了處理尾位元組 0x5C 而加的）已清除 2917 處，
  但還留著兩種要人工判斷的：行尾續行型 27 處、雙反斜線型 59 處。搜尋方式：
  `grep -rP '[\x{4e00}-\x{9fff}]\\\\$'` 與 `grep -rP '[\x{4e00}-\x{9fff}]\\\\\\\\'`。
- 新增中文內容時直接寫 UTF-8 繁體即可，不需要任何轉義。

## 架構

### 開機順序與核心物件

1. `/adm/obj/simul_efun.c` — 純聚合檔，用 `#include "/adm/simul_efun/<x>.c"` 把 69 個模組串起來。
   **新增 simul_efun 必須同時在這裡加一行**，而且順序有意義：被依賴的要排在使用者前面。
2. `/adm/obj/master.c` — driver 的 master object，`inherit` `/adm/obj/master/access.c` 與 `groups.c`。
   負責 `valid_read`/`valid_write`（權限依 `/adm/etc/access`、`/adm/etc/groups`，可不重開機更新）、
   `connect()`（clone `/std/connection`）、`compile_object()`（轉交 `VIRTUAL_D`）、
   `error_handler()`、`epilog()`/`preload()`（預載清單在 `/adm/etc/preload`）。
3. `/include/globals.h` 由驅動自動 include 進每個物件。

### 路徑巨集：一律用巨集，不要寫死路徑

- `include/mudlib.h`：`ROOM`、`NPC`、`WEAPON`、`ARMOR`、`DAEMON`、`LIVING`、`CONTAINER`、`SHOP`、`MEDICINE`… 等 inherit 目標。
- `include/daemons.h`：所有 daemon 的位置（`COMBAT_D`、`QUEST_D`、`EXPLORE_D`、`WEATHER_D`、`VIRTUAL_D`、`CMD_D`…）。
- `include/config.h`：目錄與命令搜尋路徑（`STD_CMDS`、`WIZ_CMDS`、`NEW_WIZ_PATH` 等）。
- `include/domains.h`：`DOMAIN_LIST` / `DOMAIN_DIRS`（`/d/` 下的合法領域）與巫師階級 `LEVEL_LIST`。

### 屬性系統（ob_data）

`/std/object/ob.c` = `ob_logic.c` + `prop.c`，是幾乎所有東西的根。物件狀態不是散落的變數，
而是集中在兩個 mapping：

- `ob_data` — 會存檔的資料，透過 `set("a/b/c", v)` / `query("a/b")` / `delete()` 存取，支援用 `/` 描述巢狀路徑。
- `tmp_ob_data` — `nosave` 的暫存旗標（例如房間 reset 時記錄已產生的物件）。

`query_ob_data()` 這類直接取整份 mapping 的介面有權限檢查（admin / ROOT_UID / `valid_write`）。

### 生物與玩家

`/std/body.c`（`BODY_BASE`，含 `/std/body/attack.c`、`more.c`、`alias.c`）
→ `/std/living.c`（再 inherit `/std/living/stats.c`、`edit.c`、`env.c`、`messages.c`、`/std/coinvalue.c`）
→ 分岔為 `/std/user.c`（玩家）與 `/std/npc.c`（NPC）。

**連線與身體是分離的**：`/std/connection.c` 是 interactive 物件，保存帳號、密碼、race、
巫師旗標，登入完成後連結到一個 body —— body 是 `/std/user_ob/<race>.c`（human、elf、god…），
NPC 對應 `/std/npc_ob/<race>.c`。存檔分別在 `/data/std/connection/` 與 `/data/std/user_ob/<race>/`。

戰鬥由 `/std/body/attack.c` 發動，訊息與武器動詞資料庫集中在 `/adm/daemons/combat_d.c`，
攻擊佇列與 tick 在 `/adm/daemons/attack_d.c`。

**密碼驗證一律走 `verify_password(pass, stored)`**（`/adm/simul_efun/verify_password.c`），
不要直接呼叫 `crypt()` 比對。舊存檔的密碼是 FluffOS 2017 以前驅動內建演算法的產物
（41 個字元、不以 `$` 開頭），新版 `crypt()` 認不得，只有 `oldcrypt()` 能重現；
`verify_password()` 兩種都試，回傳 2 代表「密碼正確但存的是舊格式」，
`logind.c` 會據此把該帳號的密碼就地升級成 SHA512。

### 命令系統

- 命令檔位於 `/cmds/<group>/_<name>.c`（`std`、`open`、`object`、`file`、`wiz`、`xtra`、`adm`、`ghost`）。
- 每個命令 `inherit DAEMON;`（`/std/cmd_m.c`），實作 `int cmd_<name>(string str)` 與 `int help()`；
  回傳非 0 表示已處理。
- `/adm/daemons/cmd_d.c` 掃描各目錄建立 `cmd -> path` 表（`rehash()`）。**新增命令檔後需要 rehash
  該目錄**（重新載入 `cmd_d` 或用對應巫師命令），否則找不到。
- 玩家能用哪些目錄由 `config.h` 的 `NEW_NEWBIE_PATH` / `NEW_WIZ_PATH` / `NEW_ADM_PATH` … 決定。

### 虛擬物件：`_` 前綴檔案（本 lib 最容易踩雷的地方）

`/d/` 下有兩種完全不同的寫法，看**檔名有沒有底線前綴**：

1. **一般物件**（約 5000 檔）：`inherit WEAPON;` 之類，自己 `void create()`，用 `set_name()` / `set()` 設定。
2. **虛擬物件**（約 970 檔，檔名 `_xxx.c`）：**不 inherit 任何東西**，只提供 `void create(object ob)`，
   對傳進來的 `ob` 下設定。載入流程是：
   driver 找不到 `foo.c` → `master::compile_object()` → `VIRTUAL_D`（`/adm/daemons/virtual_d.c`）
   → 往上找**同目錄的 `virtual/server.c`**（找不到才 fallback `/adm/daemons/virtual/server`）
   → server 把 `foo` 改寫成 `_foo`，`new(TEMPLATE)` 出一個 `ROOM` 或 `NPC`，
   呼叫 `_foo->create(obj)`，然後 `destruct()` 掉樣板檔本身。

   所以：**引用時寫沒有底線的路徑**（`"/d/eastland/easta/east_ent"`），編輯時改有底線的檔。
   每個區域各自有 `virtual/server.c`（全 lib 有 20+ 個），要新增區域就複製一份，`TEMPLATE` 決定產出型別。

3. **地圖式虛擬房間**：`*.east.c` 由 `/d/eastland/virtual/east_server.c` 依 `/d/eastland/eastland.map`
   （legend / room / map 三種區段）動態生成；`_x,y.east.c` 是覆寫單格地形的例外檔。

### 目錄配置

- `/adm/` — master、simul_efun 模組、daemons、`etc/`（access、groups、channels、preload 等設定）。
- `/std/` — 所有可繼承的基底類別。
- `/cmds/` — 命令。
- `/d/<domain>/` — 遊戲區域，領域清單見 `include/domains.h`；各領域有 `adm/d_master.c`、
  多半還有 `virtual/`、`monster/`、`obj/`。`eastland`（2334 檔）與 `noden`（1433 檔）是主要區域。
- `/u/<首字母>/<巫師名>/` — 巫師家目錄。
- `/obj/`、`/open/` — 共用道具與開放給新手巫師的東西。
- `/include/`、`/etc/`（新驅動設定）、`/doc/`（含 `help/`、`wizhelp/`、`lpc/` 教學）。

## 慣例與地雷

- **保留檔頭註解**：那些 TMI/ES 的作者與修改歷史是這個 lib 的慣例，改檔時在底部續寫
  `// <date> <name> - <what>` 而不是覆蓋。
- 長文字用 heredoc：`@LONG_DESCRIPTION ... LONG_DESCRIPTION` 或 `@C_LONG ... C_LONG`。
- 樹裡混雜大量**備份檔**：`*.mad`、`*.old`、`*~`、`*.new`、`*.before_stasia`、`_ls.es2`、
  `guild-bak.c`、`master.c` 旁的 `test_master.c` 等。這些不會被載入，改錯檔案是常見錯誤 ——
  以 `include/*.h` 的巨集所指向的路徑為準來判斷哪個才是活的檔案。
- 檔案開頭常見被註解掉的 `//#pragma save_binary`，維持原狀即可。
- **舊式巨集拼接浮點數會被新 lexer 拆開**：`AVERAGING_NUM.0` 在 FluffOS 2019 以後會解析成
  `12 . 0` 而編譯失敗（已修 `adm/daemons/usage_d.c`）。要浮點請寫 `(float)MACRO`。
- `.vscode/c_cpp_properties.json` 把 `.c` 當 C89 處理並強制 include `globals.h`，
  `C_Cpp.errorSquiggles` 是關掉的 —— 編輯器的錯誤提示對 LPC 沒有參考價值。
- LPC 不是 C：`mapping`、`mixed`、`([ ])`、`({ })`、`->`、`call_other`、`efun`/`simul_efun`、
  `varargs`、`nosave`、`nomask`。語法參考在 `/doc/lpc/`。
