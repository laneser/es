# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

東方故事 MUD —— 繁體中文 LPMud，跑在 FluffOS 上。這個 repo 是 **mudlib**（用 LPC
寫的遊戲世界），驅動本身由 `.devcontainer/` 從 source 建置，不在 repo 裡。
mudlib 自稱 `ES_Lib`，血緣是 TMI-2 mudlib 的中文化分支，檔案多數寫於 1992–2001 年。

**架構、設計決策、技術債請看 [`doc/arc42/`](doc/arc42/README.md)。**
這份檔案只寫「現在要動手需要知道的」。

沒有 build system、套件管理或 linter。所有 `.c` 都是 LPC，由驅動在執行期即時編譯，
「部署」等於在遊戲內 `update` 重新載入物件。

## 啟動

```bash
docker build -t es-mud-fluffos:2026.0901 -f .devcontainer/Dockerfile .devcontainer
docker run -d --name es-mud -p 8888:8888 -v "$PWD":/mudlib -w /mudlib \
  es-mud-fluffos:2026.0901 driver /mudlib/etc/fluffos.cfg
docker exec -it es-mud telnet 127.0.0.1 8888    # 容器內已裝 telnet
```

- 設定檔是 **`etc/fluffos.cfg`**，不是根目錄的 `config.cfg`（後者是舊格式，留作對照）。
  裡面標示「相容」的開關是為了讓 1990 年代的 LPC 照原本語意運作，**改動會改變既有程式行為**。
- 帳號 `admin` / `12345`（另有 `mudren`）。
- 用 `127.0.0.1` 而非 `localhost`：driver 只綁 IPv4。
- `log/`、`tmp/`、`data/` 是執行期產物。`data/` 被 git 追蹤，
  **跑過遊戲後 `git status` 一定不乾淨**，commit 前要確認沒把測試痕跡送出去。

## 遊戲內的開發迴圈

指令都在 `/cmds/` 下、檔名為 `_<name>.c`：

- `update <file>` 重新編譯載入單一物件；`update -r/-R` 連同 inherit 鏈深度更新
  （改 `/std/user.c` 這類基底檔時需要）。不帶參數時用玩家的 `cwf`。
- `clone` / `dest` / `load` / `goto` / `at` / `eval` —— 實例化與檢視。
- `data` / `datatmp` / `sc` / `ss` —— 檢視物件的 `ob_data` / `tmp_ob_data`。

**改 simul_efun 或 master 之後要重啟 driver**，`update` 不夠。

## 測試

```
lest /obj        對目錄底下所有 .c 跑測試（load 一遍 + 跑 spec）
lest             顯示上次的報告（含覆蓋率與失敗明細）
lest -u          列出還沒有 spec 的檔案
help lest        完整說明
```

`xxx.c` 旁邊放 `xxx.spec.c` 就會被執行，`test_` 開頭的函式自動被找出來：

```c
#include <lest.h>
inherit SPEC;

void test_c_name(object ob) { expect_eq(ob->query("c_name"), "繃帶", "中文名"); }
```

細節與現有 spec 清單見 [`doc/arc42/10-quality-and-testing.md`](doc/arc42/10-quality-and-testing.md)。

**執行期錯誤看 `log/debug.log`**（中文的「執行時段錯誤」，含完整呼叫堆疊與觸發者），
**編譯錯誤看 `d/<領域>/log`**（依領域分類）。
`lest` 只抓得到編譯期問題，執行期的型別錯誤要靠實際遊玩加上讀 log。

⚠️ **driver 執行中不要 `rm log/debug.log`** —— driver 持有那個 handle，
刪掉之後錯誤全部寫進虛空，要連帶重啟。mudlib 寫的 log（領域 log、`log/lest`）則沒事。

## 編碼：UTF-8 繁體中文

全樹 UTF-8。從 Big5 → GBK → UTF-8 轉過兩次，留下三種痕跡：

- 少數 `□`（U+25A1）缺字，例如 `cmds/std/_look.c:406`。無法自動修復。
- 27 處行尾續行型、59 處雙反斜線型的殘留轉義反斜線未處理。
- `data/attic/` 16 個檔含 U+FFFD。

**LPC 識別字只能用 ASCII** —— 函式名寫英文，中文放字串與註解裡。
`void test_中文名()` 會得到 `Illegal character 0xe4`。

## 最容易踩的地雷

### `_` 前綴的虛擬物件

`/d/` 下約 970 個 `_foo.c` **不繼承任何東西**，只提供 `void create(object ob)`，
由同目錄的 `virtual/server.c` 生成。

**引用時寫不含底線的路徑**（`/d/eastland/easta/east_ent`），**編輯時改有底線的檔**。

機制詳見 [`doc/arc42/08-crosscutting-concepts.md`](doc/arc42/08-crosscutting-concepts.md)。

### simul_efun 必須在聚合檔裡

新增 `/adm/simul_efun/xxx.c` 之後**一定要在 `/adm/obj/simul_efun.c` 加一行 include**，
而且**順序有意義**（被依賴的排前面）。

⚠️ 該目錄下有 5 個檔案**沒有被 include**：`message.c`、`help.c`、`lines.c`、
`cat.1208.c`、`data.1208.c`。改它們不會有任何效果。動手前先確認它在聚合檔裡。

### 一律用巨集，不要寫死路徑

`include/mudlib.h`（`ROOM`、`NPC`、`WEAPON`、`DAEMON`…）、
`include/daemons.h`、`include/config.h`、`include/domains.h`。

### 樹裡混雜大量備份檔

`*.mad`、`*.old`、`*~`、`*.new`、`*.before_stasia`、`guild-bak.c`、`test_master.c`…
不會被載入，但會出現在 grep 結果裡。**改錯檔案是這個 repo 最常見的錯誤** ——
以 `include/*.h` 的巨集所指的路徑為準。

### 保留檔頭

TMI/ES 原作者的檔頭與修改紀錄是這個 lib 的口述歷史。改檔時在底部續寫
`// <date> <name> - <what>`，不要覆蓋。

## FluffOS 2019+ 破壞性變更速查

這個 mudlib 寫於 MudOS 0.9.20 時代。下列都已修，但**同類問題還散落在沒被執行到的
程式碼裡**（例如約 178 個未檢查空值的 `userp()`/`wizardp()` 呼叫點）。

| 變更 | 症狀 | 怎麼寫才對 |
|---|---|---|
| `message()` 第 4 參數只收 object/array | `Bad argument 4 to EFUN message()` | 省略不傳是合法的，明確傳 `0` 才炸。`varargs` 函式要自己正規化 |
| `ref` 是保留字（`new`、`array` 同理） | `syntax error, unexpected L_REF` | 改名 |
| `userp()`/`wizardp()` 收到 0 會拋錯 | `Bad argument 1 to userp()` | `if( ob && userp(ob) )` |
| `crypt()` 改走系統 crypt | 舊帳號全部登入失敗 | 一律走 `verify_password()` |
| `#include <相對路徑>` 無效 | `Cannot #include ...` | 相對路徑與同目錄標頭用雙引號 |
| `__FILE__` 指「當前檔案」 | include 檔裡會指到它自己 | 用 `base_name(this_object())` |
| 巨集拼接浮點被拆開 | `AVERAGING_NUM.0` → `12 . 0` | 寫 `(float)MACRO` |
| 執行期錯誤中斷整個呼叫鏈 | 被 `heart_beat` 週期呼叫的函式會不斷重跑 | 防重入旗標立在函式**最前面** |

每一項的完整脈絡與取捨見
[`doc/arc42/09-architecture-decisions.md`](doc/arc42/09-architecture-decisions.md)。

## LPC 不是 C

`mapping`（`([ ])`）、陣列（`({ })`）、`mixed`、`->`（`call_other`）、
`varargs`、`nosave`、`nomask`。長文字用 heredoc（`@LONG_DESCRIPTION ... LONG_DESCRIPTION`）。
語法參考在 `/doc/lpc/`，術語見 [`doc/arc42/12-glossary.md`](doc/arc42/12-glossary.md)。

`.vscode/c_cpp_properties.json` 把 `.c` 當 C89 並關掉 `errorSquiggles` ——
編輯器的紅線對 LPC 沒有參考價值。
