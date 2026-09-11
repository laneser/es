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
