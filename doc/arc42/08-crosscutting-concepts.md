# 08 橫切概念

## 屬性系統（ob_data）

`/std/object/prop.c`，被 `/std/object/ob.c` include，而幾乎所有東西都繼承 `ob.c`。

```c
mapping ob_data;               // 會存檔
nosave mapping tmp_ob_data;    // 不存檔
nosave mixed default_ob;       // 查不到時轉問誰
```

| 函式 | 作用 |
|---|---|
| `set(label, value)` | 設定；`label` 可以是 `"wealth/gold"` 這種巢狀路徑 |
| `query(label)` | 取值 |
| `delete(label)` | 刪除 |
| `add(label, n)` | 累加（原本沒有就等於 set） |
| `set_temp` / `query_temp` / `delete_temp` / `add_temp` | 同上，但操作 `tmp_ob_data` |

三個容易忽略的語意：

**巢狀路徑。** `set("wealth/gold", 75)` 會在 `ob_data` 裡建出
`([ "wealth": ([ "gold": 75 ]) ])`，`query("wealth")` 拿到的是中間那層 mapping。

**`@@` 轉呼叫。** 值如果是 `"@@函式名"` 這種字串，`query()` 會轉成對自己
呼叫那個函式並回傳結果。所以物件裡常見 `set("short", "@@query_short")` ——
短描述是動態計算的，不是固定字串。

**`default_ob` 轉問。** 查不到的 label 會轉問 `default_ob`。
`include/compress_obj.h` 靠這個讓 clone 出來的物件不必自己存一份完整的
`ob_data`，直接轉問 blueprint，省下大量重複的 mapping。

`query_ob_data()` 這種直接取整份 mapping 的介面有權限檢查
（admin / ROOT_UID / `valid_write`）。

相關測試：`/std/object/ob.spec.c`。

## 權限：uid 與 euid

每個物件有兩個身分：**uid**（出身，由檔案路徑決定）與 **euid**（有效身分，可變更）。

`master.c::creator_file()` 依路徑第一段決定 uid：

| 路徑 | uid |
|---|---|
| `/adm/...` | `Root`（但 simul_efun 本身是 `NONAME`） |
| `/cmds/...` | `Root` |
| `/std/...` | `NONAME`（`/std/user` 例外為 `Backbone`） |
| `/obj/...` | `Backbone` |
| `/d/<領域>/...` | 領域名首字大寫，例如 `Eastland` |
| `/u/<首字母>/<名>/...` | 該巫師名 |
| `/open/...` | `Anonymous` |

檔案存取時驅動呼叫 `valid_read` / `valid_write`，master 去查兩份設定：

- **`/adm/etc/groups`** —— 群組定義，例如 `(root) :mudren:admin`
- **`/adm/etc/access`** —— 目錄權限，例如 `(/) (all)[r]:(root)[rw]:(admin)[rw]`

兩份都是**執行期讀取**的，改了不必重開機。

`seteuid()` 受 `valid_seteuid()` 管制。daemon 常在 `create()` 裡
`seteuid(getuid())` 把自己的有效身分設回出身。

## 虛擬物件

`/d/` 底下有兩種完全不同的寫法，**看檔名有沒有底線前綴**：

| | 一般物件（約 5000 檔） | 虛擬物件（約 970 檔） |
|---|---|---|
| 檔名 | `foo.c` | `_foo.c` |
| 繼承 | `inherit WEAPON;` 之類 | **不繼承任何東西** |
| 進入點 | `void create()` | `void create(object ob)` |
| 誰呼叫 | 驅動 | 同目錄的 `virtual/server.c` |
| 引用路徑 | `/d/x/foo` | `/d/x/foo`（**不含底線**） |

生成流程見 [06 執行期視圖](06-runtime-view.md)。

**最常見的錯誤**：引用時寫成含底線的路徑，或是去改沒有底線的那個（不存在的）檔案。

## 心跳與節奏

見 [06 執行期視圖](06-runtime-view.md) 的心跳章節。要點：

- 指令走佇列，由 `heart_beat()` 取出
- `MAX_TICK = 8`（`include/body.h`）決定戰鬥回合相對於心跳的倍率
- 改 `heartbeat interval msec` 會同時改變戰鬥節奏、NPC 行為、狀態恢復速度，
  不是單純調快回應

## 存檔快照

一個玩家有兩份存檔，兩份都要一起處理，分開還原會對不起來：

| | 路徑 | 內容 |
|---|---|---|
| 連線 | `data/std/connection/<首字母>/<name>.o` | 帳號、密碼、種族、巫師旗標 |
| 軀殼 | `data/std/user_ob/<種族>/<首字母>/<name>.o` | 屬性、經驗值、身上的東西 |

`save_object()` 只會蓋掉這兩個檔。`/adm/daemons/snapshotd.c` 掛在
`/std/user/save.c` 的 `save_me()` 後面，每次存完另外留一份副本到
`data/snapshots/`（路徑與正式存檔平行，多一層 `<name>/`）：

- **近期環** —— 檔名是時戳，保留最新 24 份。同一玩家兩次快照至少隔 5 分鐘
  （`SNAPSHOT_GAP`），免得反覆登入登出把歷史洗掉；這個值**必須小於
  `AUTOSAVE`**，否則定時存檔留不下快照。
- **長期三格** —— `d1-` / `d7-` / `d30-`，大約是一天前、一週前、一個月前。
  由 `plan_cascade()` 逐格往下推：一格的住戶撐滿該格的年限才換人，而且
  來源自己要先在上一格待滿才有資格往下推（少了後面這關，剛開機的頭一個
  小時就會把幾分鐘前的東西塞滿三格）。剛開始跑的第一個月，`d30` 會比
  標籤講的年輕。

推格與汰換的規則寫成不碰檔案的純函式（`plan_cascade()`、`plan_trim()`），
由 `snapshotd.spec.c` 直接餵檔名清單驗證 —— 這種錯不會當場報錯，只會在
一個月後才發現「一個月前那份」是昨天的。

遊戲內用 `snapshot <玩家>` 列出、`snapshot <玩家> <時戳|d1|d7|d30>` 還原
（還原限 admin，且該玩家必須不在線上）。跟既有的 `backup` / `restore`
不衝突：那一組只保留最後一份。

## 錯誤處理

LPC 的執行期錯誤會**中止整個呼叫鏈**，但不影響其他物件。
`master.c::error_handler()` 收到錯誤後：

1. 格式化成中文的「執行時段錯誤」＋完整呼叫堆疊
2. 傳給觸發錯誤的玩家（畫面上）
3. 回傳值加上時間戳與觸發者，寫進 `log/debug.log`

編譯錯誤走另一條路：`master.c::log_error()` 依檔案路徑歸屬，
寫到 `/d/<領域>/log` 或 `/u/<巫師>/log`，同樣帶時間戳。

**危險的模式**：被 `heart_beat` 週期呼叫的函式，一旦中途拋錯就會不斷從頭重跑。
`die()` 的屍體無限增生就是這樣來的。這類函式的防重入旗標必須立在**最前面**。

## 編碼

全樹 UTF-8、繁體中文。歷史與殘留痕跡見 [02 限制條件](02-constraints.md)。

**LPC 識別字只能用 ASCII** —— 函式名、變數名不能用中文，
`void test_中文名()` 會得到 `Illegal character 0xe4`。

## 訊息輸出

| 函式 | 用途 |
|---|---|
| `write(msg)` | 給 `this_player()` |
| `tell_object(ob, msg)` | 給特定物件 |
| `tell_room(room, msg [, exclude])` | 給房間裡所有人 |
| `say(msg [, exclude])` | 給同房間的人（自動排除自己） |
| `shout(msg [, exclude])` | 給全世界 |

底層都是驅動的 `message()` efun。
**`message()` 的第四個參數（排除名單）只接受 object 或 array，不接受 `0`** ——
省略不傳是合法的，明確傳 `0` 才會拋錯。`tell_room()` 是 varargs，
所以它負責把省略的參數正規化成空陣列，呼叫端可以照常只給兩個參數。

相關測試：`/adm/simul_efun/tell_room.spec.c`。
