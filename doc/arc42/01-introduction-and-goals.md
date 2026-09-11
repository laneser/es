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
