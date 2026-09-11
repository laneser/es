# 12 詞彙表

## LPMud 基本概念

| 詞 | 意思 |
|---|---|
| **driver** | 用 C++ 寫的執行環境：編譯並執行 LPC、處理網路、排程心跳。這個專案用 FluffOS |
| **mudlib** | 用 LPC 寫的遊戲世界本身，也就是這個 repo。driver 不知道任何遊戲規則 |
| **LPC** | driver 執行的語言。語法像 C，但有 mapping、動態型別、物件導向 |
| **efun** | external function，driver 直接提供的內建函式，例如 `write()`、`clone_object()` |
| **simul_efun** | simulated efun，用 LPC 寫的「偽 efun」，全遊戲可直接呼叫。見 `/adm/obj/simul_efun.c` |
| **apply** | driver 在特定時機反過來呼叫 mudlib 的函式，例如 `create()`、`heart_beat()`、master 的 `valid_read()` |
| **master object** | mudlib 對 driver 的唯一控制面，`/adm/obj/master.c` |

## 物件

| 詞 | 意思 |
|---|---|
| **blueprint** | 一個 `.c` 檔第一次被載入時產生的原型物件，路徑就是檔名 |
| **clone** | 用 `clone_object()` / `new()` 從 blueprint 複製出來的實例，名稱帶 `#編號` |
| **虛擬物件** | 檔案不存在、由 `virtual/server.c` 動態生成的物件。見 [08](08-crosscutting-concepts.md) |
| **ob_data** | 物件屬性集中存放的 mapping，會存檔。`tmp_ob_data` 是不存檔的版本 |
| **uid / euid** | 物件的出身身分與有效身分，決定檔案存取權限 |

## 遊戲

| 詞 | 意思 |
|---|---|
| **wizard（巫師）** | 有寫程式權限的使用者，在遊戲裡開發 |
| **domain（領域）** | `/d/` 底下的一個遊戲區域，例如 `eastland`、`noden`。清單在 `include/domains.h` |
| **daemon** | 常駐的單例服務物件，住在 `/adm/daemons/`。清單在 `include/daemons.h` |
| **body / connection** | 身體物件與連線物件，這個 lib 刻意把兩者分開。見 [06](06-runtime-view.md) |
| **linkdead** | 玩家斷線但身體還留在世界裡的狀態，會被移到 `/d/std/rooms/netdead`（時間的縫隙） |
| **heart_beat** | 週期性呼叫的 apply，驅動指令佇列、戰鬥回合、體力恢復 |
| **reset** | 房間週期性重生道具與 NPC 的機制 |

## 這個 codebase 特有

| 詞 | 意思 |
|---|---|
| **ES / ES_Lib** | Eastern Stories，這份 mudlib 的自稱（`include/config.h`） |
| **TMI-2** | The Mud Institute 的第二版 mudlib，這份 lib 的血緣來源 |
| **lest** | LPC test，這個專案自己寫的測試執行器。見 [10](10-quality-and-testing.md) |
| **spec** | `xxx.spec.c`，`xxx.c` 的測試檔 |
| **`_` 前綴檔** | 虛擬物件的樣板檔，例如 `_east_ent.c`。引用時路徑不含底線 |
| **死檔** | 還在樹裡但已經不會被載入的檔案：`*.mad`、`*.old`、`*~`、`guild-bak.c`，以及未被 include 的 simul_efun 模組 |

## 容易混淆的

- **`.o` 檔不是編譯產物**，是 `save_object()` 存的純文字存檔。
  副檔名由驅動的 `__SAVE_EXTENSION__` 決定，剛好也叫 `.o`
- **`/std/room/room.c` 不是 `/std/room`**，後者不存在。`include/mudlib.h`
  的 `ROOM` 巨集指向前者
- **`ref` 是保留字**，不能當變數名（新驅動）
- **`__FILE__` 指「當前檔案」**，寫在 include 檔裡就會指到那個 include 檔
