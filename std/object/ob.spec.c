//  File     : /std/object/ob.spec.c
//  /std/object/ob.c 的 spec —— ob_data 屬性系統是幾乎所有東西的根，
//  這裡把它的核心語意釘住：巢狀路徑、@@ 轉呼叫、tmp 不存檔、default_ob 轉問。
//  06-09-11 建立

#include <lest.h>

inherit SPEC;

void test_set_and_query(object ob)
{
	ob->set("colour", "red");
	expect_eq( ob->query("colour"), "red", "set 之後 query 應該拿得回來" );
}

void test_nested_path(object ob)
{
	//  set("a/b/c", v) 會在 ob_data 裡建出巢狀 mapping，query 用同樣的路徑取回
	ob->set("wealth/gold", 75);
	expect_eq( ob->query("wealth/gold"), 75, "巢狀路徑 set/query" );
	expect_true( mapp(ob->query("wealth")), "中間層應該是個 mapping" );
}

void test_delete(object ob)
{
	ob->set("doomed", 1);
	ob->delete("doomed");
	expect_true( undefinedp(ob->query("doomed")), "delete 之後應該查不到" );
}

void test_add(object ob)
{
	ob->set("count", 3);
	ob->add("count", 4);
	expect_eq( ob->query("count"), 7, "add 應該累加到既有值上" );
}

void test_add_on_empty(object ob)
{
	ob->add("fresh", 5);
	expect_eq( ob->query("fresh"), 5, "對不存在的 label 做 add 應該等於直接 set" );
}

void test_temp_is_separate(object ob)
{
	//  tmp_ob_data 是 nosave 的，和 ob_data 完全分開 —— 兩者同名不該互相看見
	ob->set("dual", "saved");
	ob->set_temp("dual", "temporary");
	expect_eq( ob->query("dual"), "saved", "query 只看 ob_data" );
	expect_eq( ob->query_temp("dual"), "temporary", "query_temp 只看 tmp_ob_data" );
}

void test_at_at_dispatch(object ob)
{
	//  值若是 "@@函式名"，query 會轉成對自己呼叫那個函式。
	//  這是 short/long 那些 "@@query_short" 的運作方式。
	ob->set("probe", "@@query_default_ob");
	ob->set_default_ob("/obj/bandage");
	expect_eq( ob->query("probe"), "/obj/bandage",
		"@@ 開頭的值應該轉呼叫同名函式，而不是回傳字串本身" );
}

void test_default_ob_fallback(object ob)
{
	//  查不到的 label 會轉問 default_ob —— compress_obj.h 靠這個讓 clone
	//  不必自己存一份完整的 ob_data
	ob->set_default_ob("/obj/bandage");
	expect_eq( ob->query("c_name"), "繃帶",
		"自己沒有的 label 應該轉問 default_ob" );
}

void test_own_value_wins_over_default(object ob)
{
	ob->set_default_ob("/obj/bandage");
	ob->set("c_name", "自己的名字");
	expect_eq( ob->query("c_name"), "自己的名字",
		"自己有值時不該被 default_ob 蓋掉" );
}
