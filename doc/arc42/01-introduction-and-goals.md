# 01 導論與目標

## 這是什麼

東方故事（Eastern Stories）是一個**繁體中文的 LPMud**。玩家用 telnet 連進來，
在一個文字描述的武俠／奇幻世界裡探索、戰鬥、練功、彼此交談。

技術上它由兩層組成：

- **驅動（driver）** —— FluffOS，一個用 C++ 寫的 LPC 直譯器與網路伺服器。
  這個 repo **不包含**驅動原始碼，只包含建置它的 `.devcontainer/Dockerfile`
  與執行設定 `etc/fluffos.cfg`。
- **mudlib** —— 就是這個 repo。用 LPC 寫成的遊戲世界本身：物件系統、
  權限模型、指令、房間、NPC、技能、戰鬥規則。驅動不知道任何遊戲規則，
  它只負責編譯 LPC、跑物件、收發網路封包。

mudlib 自稱 `ES_Lib`（`include/config.h`），血緣上是 **TMI-2 mudlib** 的中文化分支。
大量檔案仍帶著 1992–1995 年 TMI 原作者的檔頭與修改紀錄，之後由
Annihilator、Ruby、Iris 等人在台灣接手中文化與改造。

## 這份快照是什麼年代的

repo 裡沒有原始的備份說明，但 `data/` 底下 528 個留言板存檔替它自己記了帳。
每則留言都帶一個 `"time":<unix epoch>` 欄位，全樹一共 23959 則，
把它們排出來就是這個站的生命線（以下皆為台北時間）：

| 期間 | 留言數 | 發生了什麼 |
|---|---|---|
| 1993-11 ~ 1996-10 | 23368 | TMI-2 中文化後的主要營運期，1995 年最盛（18428 則） |
| 1996-11 ~ 1997-10 | **0** | 全站停擺整整一年 |
| 1997-11 ~ 1998-06 | 591 | 小規模重啟，只剩 `bugs_board`、`wiz_board`、`healer_board` 有人 |
| 1998-06-15 ~ 2001-05-20 | **0** | 近三年空白 |
| 2001-05-21 ~ 05-28 | 1 | 有人把這份 lib 重新架起來跑了約一週 |

兩個日期要分開講，它們常被混為一談：

### 世界內容凍結於 1998-06-14

最後一則有社群意義的留言在 `d/wiz/data/wiz_board.o`，1998-06-14 09:31，
巫師 Snow 寫「又收到一個申請當巫師，現在我們人手基本上還可以，
所以申請暫時不要太輕易接收」——一副還在正常營運的樣子，然後就斷了。

**這之後沒有任何新的區域、NPC 或劇情內容加進來。** 你現在讀到的遊戲世界，
實質上是 1998 年 6 月的樣子。

### 但檔案快照不早於 2001-05-28

2001 年 5 月有人把這份 lib 撿起來重新架站，而且**動了核心程式碼**，
三處都留了署名：

| 檔案 | 改了什麼 |
|---|---|
| [`std/body/armor_class.c:1`](../../std/body/armor_class.c) | `//add by cach 2001.5` + 補上一批函式原型 |
| [`adm/daemons/attack_d.c:23`](../../adm/daemons/attack_d.c) | `//add by cach 2001.5`，把 `die()` 改成 `varargs protected void die(int silent)` |
| [`cmds/std/_levels.c:10`](../../cmds/std/_levels.c) | `//by cach 2001.5`，補 `#include <mudlib.h>`、`<org.h>` |

同一個 Cach 在 2001-05-21 21:37 於 `d/monk/data/monk_board.o` 留下全站最後一則留言
——那個檔整個只有這一則，板子是清空重開的：

```
"poster":"Cach","time":990452244,"title":"haha","body":"第一個來！"
```

`creative`、`haha`、`cach` 三個帳號的 `last_save` 最晚到 2001-05-28 01:28
（`data/std/user_ob/`）。**因此這份 repo 的打包時間不可能早於 2001-05-28。**

這些 2001 年的修改看起來就是「讓舊 lib 在新驅動上跑起來」的修補——
補原型、補 include、調 varargs 簽名。跟本次升級做的事同一類，只是隔了 25 年。

### 2021-08-17 那筆不算

`data/std/user_ob/elf/m/mudren.o` 與對應的 connection 檔帶著
2021-08-17 17:38 的時間戳。那是後來有人把這份 mudlib 拿起來試跑一次的痕跡，
只有登入、沒有任何內容產出，**不要把它當成原站的營運紀錄**。
`data/` 被 git 追蹤，這類痕跡會一直累積（見
[11 風險與技術債](11-risks-and-technical-debt.md) 的「`data/` 被 git 追蹤」）。

### 怎麼自己驗一次

```bash
# 全樹留言時間戳，最新的在最後
grep -rho '"time":[0-9]\{9,10\}' --include='*.o' --exclude-dir=.git . \
  | sed 's/.*://' | sort -n | tail -5 \
  | while read ts; do echo "$ts $(TZ=Asia/Taipei date -r $ts '+%Y-%m-%d %H:%M')"; done
```

`d/*/data/attic/` 底下的檔名尾巴（例如 `water_board_844506105.o`）
是**這塊板被歸檔時**的 epoch，不是板裡最新留言的時間，兩者可以差好幾個月。

## 使用者與角色

| 角色 | 能做什麼 | 技術上如何區分 |
|---|---|---|
| 玩家 | 探索、戰鬥、交談 | `PATH` 只含 `/cmds/std` |
| 巫師（wizard） | 寫程式、建區域、`update` 物件 | connection 物件的 `wizard` 旗標；`PATH` 加上 `/cmds/wiz` 等 |
| 管理員（admin） | 關機、改權限、管帳號 | `/adm/etc/groups` 的 `(admin)` 群組 |

巫師是這個系統的第二群使用者，而且是**在遊戲裡面寫程式**的 ——
這件事深刻影響了整個架構（見 [04 解決策略](04-solution-strategy.md)）。

## 什麼算成功

依重要性排序：

1. **玩家的資料不能壞。** 角色存檔（`/data/std/`）是唯一不可重建的東西。
2. **一個錯誤不能拖垮整個世界。** LPC 的執行期錯誤只該中止當前呼叫鏈，
   其他玩家繼續玩。這一點在升級驅動時被打破過 —— 見
   [11 風險與技術債](11-risks-and-technical-debt.md) 的「屍體無限增生」。
3. **巫師改完能立刻看到結果。** `update` 一個物件就生效，不必重開整個遊戲。
4. 回應要夠快。指令延遲由心跳決定，見 [08 橫切概念](08-crosscutting-concepts.md)。

注意這裡沒有「高可用」「水平擴展」這類目標。這是單一程序、單機、
最多 50 人同時在線（`etc/fluffos.cfg` 的 `maximum users`）的系統。
