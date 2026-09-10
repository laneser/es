// This include file is created for reduce the mapping of ob_data[] of
// simple items ( which inherit only /std/object/ob.c )
// It is provided by Annihilator@ES
// Ruby@ES add this include file at 95' 6/26
//
// 注意這不是一般的標頭檔，而是一段直接貼進 create() 開頭的程式碼：
// clone 出來的物件不再自己建一份 ob_data，而是把 default_ob 指向 blueprint，
// query() 查不到值時再轉問它，藉此省下大量重複的 mapping。
//
// 06-09-10 原本這裡寫的是 set_default_ob(__FILE__)。舊驅動的 __FILE__ 展開成
//          「使用這個 include 的那個檔案」，新驅動則展開成 include 檔自己的路徑，
//          於是 default_ob 變成 "/include/compress_obj.h"，query() 一轉問就拋出
//          call_other() couldn't find object '/include/compress_obj.h'。
//          改用 base_name(this_object())：對 clone 物件它回傳不含 #編號 的
//          blueprint 路徑，正是這裡要的東西，而且不依賴 __FILE__ 的展開語義。

if ( clonep(this_object()) ) {
	set_default_ob(base_name(this_object()));
	return;
}
