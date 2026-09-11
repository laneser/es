//  File     : /obj/torch.spec.c
//  /obj/torch.c 的 spec。
//  06-09-11 建立

#include <lest.h>

inherit SPEC;

void test_c_name(object ob)
{
	expect_eq( ob->query("c_name"), "火把", "中文名應該是火把" );
}

void test_unit(object ob)
{
	expect_eq( ob->query("unit"), "枝", "量詞應該是枝" );
}

void test_value(object ob)
{
	expect_true( pointerp(ob->query("value")), "value 應該是 ({ 數量, 幣別 }) 形式" );
}

void test_can_be_lit(object ob)
{
	//  火把剛做出來是沒點燃的（light 要等 light_t() 被呼叫才設成 1），
	//  所以這裡驗的是「點得起來」，不是「現在亮著」。
	expect_true( function_exists("light_t", ob), "應該要能被點燃（light_t）" );
}

void test_not_lit_initially(object ob)
{
	expect_true( !ob->query("light"), "剛做出來的火把不該是亮的" );
}

void test_has_fuel(object ob)
{
	expect_gt( ob->query("fuel"), 0, "應該有燃料秒數，否則點了就滅" );
}
