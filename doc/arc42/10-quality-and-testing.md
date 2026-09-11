# 10 品質與測試

## 三層防線

沒有任何單一工具能涵蓋這個系統的錯誤類型，實務上是三層疊起來：

| 層 | 工具 | 抓得到 | 抓不到 |
|---|---|---|---|
| 1 | `lest <目錄>` | 語法錯誤、inherit 斷裂、include 找不到 | 任何要執行到才發生的事 |
| 2 | `xxx.spec.c` | 行為回歸（屬性、邊界、例外） | 沒寫 spec 的地方 |
| 3 | 實際遊玩 + 讀 `log/debug.log` | 執行期型別錯誤、流程中斷 | 沒走到的路徑 |

**第三層是主力。** 這次升級真正咬人的四個 bug——`message()` 的排除名單、
`userp(0)`、`tell_room` 的 varargs、`__FILE__` 展開——第一層一個都攔不下來，
因為它們在語法和型別上完全合法。抓到它們的是「登入、走一走、死一死」。

## lest

巫師指令，`help lest` 有完整說明。

```
lest /obj        對目錄底下所有 .c 跑測試
lest             顯示上次的報告
lest -u          列出還沒有 spec 的檔案
```

實作在 `/adm/daemons/lest_d.c`。報告長這樣：

```
===== lest 報告：/obj =====
受測檔案      : 47
  載入成功    : 43
  載入失敗    : 4
有 spec 的檔案: 2  (覆蓋率 4.2%)
  斷言通過    : 12
  斷言失敗    : 0
```

### 寫一個 spec

`xxx.c` 旁邊放 `xxx.spec.c`：

```c
#include <lest.h>
inherit SPEC;

void test_c_name(object ob) { expect_eq(ob->query("c_name"), "繃帶", "中文名"); }
void test_weight(object ob) { expect_gt(ob->query("weight"), 0, "重量為正"); }
```

- 函式名以 `test_` 開頭的會被 `functions()` 自動找出來執行
- 參數是受測物件，預設 `clone_object()`；房間或 daemon 這種不該 clone 的，
  覆寫 `lest_subject(string target)` 自己決定怎麼取得
  （simul_efun 這種沒有實體的，回傳 0）
- 跑完 `lest_cleanup()` 把東西收掉，預設 `destruct()`
- 斷言：`expect_eq`、`expect_ne`、`expect_gt`、`expect_true`、
  `expect_object`、`expect_string`，以及自己給條件的 `expect`
- **函式名只能用 ASCII**，中文寫在斷言描述裡

### 現有的 spec

| spec | 斷言 | 保護什麼 |
|---|---|---|
| `/std/object/ob.spec.c` | 11 | 屬性系統：巢狀路徑、`@@` 轉呼叫、temp 隔離、default_ob |
| `/adm/simul_efun/verify_password.spec.c` | 9 | 新舊密碼格式、錯誤密碼、垃圾輸入 |
| `/adm/simul_efun/tell_room.spec.c` | 5 | 少給參數不能炸 |
| `/std/weapon/weapon.spec.c` | 7 | `setup_weapon()` 的四個值 |
| `/std/room/room.spec.c` | 7 | `valid_exit` 的三種情況 |
| `/obj/bandage.spec.c`、`/obj/torch.spec.c` | 12 | 範例 |

`/obj/torch.spec.c` 值得一讀：火把的 `light` 屬性要點燃後才有，
所以測的是「點得起來」而不是「現在亮著」。**測試失敗時第一件事是
判斷錯的是程式還是測試** —— 這個例子的第一版就是測試寫錯。

### 該給誰寫 spec

不是每個檔案都值得。`/d/` 底下幾千個房間描述檔測不出什麼。
值得寫的是**被大量複用**與**最近改動**的：`/std/`（基底類別）、
`/adm/daemons/`、`/adm/simul_efun/`、`/obj/`。

`lest -u` 列出未覆蓋清單，可以拿來決定下一個補哪裡。

## 除錯入口

| 檔案 | 誰寫的 | 內容 |
|---|---|---|
| `log/debug.log` | 驅動 | 執行期錯誤（含完整呼叫堆疊與觸發者）、編譯警告 |
| `d/<領域>/log`、`/u/<巫師>/log` | mudlib | 編譯錯誤與警告，**依領域分類** |
| `log/lest` | mudlib | 測試與掃描結果 |

錯誤訊息是中文的，grep 關鍵字是「執行時段錯誤」。

**領域 log 特別值得翻**，它已經幫你按區域分好類了。實例：
`d/adventurer/log` 直接指出 `_yubi.c:58` 的 `if( !me->query_attacker(); )`
多了一個分號——那個檔案從 1990 年代起就沒有編譯成功過。

比起清掉 log 重看，更好的做法是**留著檔案比對差異**：

```bash
cp d/adventurer/log /tmp/before
# ...重現問題...
diff /tmp/before d/adventurer/log
```

注意 `log/debug.log` 在 driver 執行中不能刪，見
[07 部署視圖](07-deployment-view.md)。

## 目前的覆蓋狀況

以核心目錄（`/std`、`/cmds`、`/adm`、`/obj`）746 個檔案計：

- 載入成功率約 96%，失敗的 32 個絕大多數是 inherit 早已不存在的檔案的**死檔殘骸**
- spec 覆蓋率極低（個位數百分比），這是刻意的起步狀態

覆蓋率這個數字對這個 codebase 意義有限——分母裡有幾千個房間描述檔。
比較有意義的問法是「被大量複用的東西有沒有被保護」。
