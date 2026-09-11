//  File     : /obj/bandage.spec.c
//  /obj/bandage.c 的 spec。用法見 help lest。
//  注意：LPC 的識別字只能用 ASCII，函式名請用英文，中文寫在斷言描述裡。
//  06-09-11 建立

#include <lest.h>

inherit SPEC;

void test_c_name(object ob)
{
	expect_eq( ob->query("c_name"), "繃帶", "中文名應該是繃帶" );
}

void test_name(object ob)
{
	expect_eq( ob->query("name"), "bandage", "英文名應該是 bandage" );
}

void test_unit(object ob)
{
	expect_eq( ob->query("unit"), "條", "量詞應該是條" );
}

void test_weight(object ob)
{
	expect_gt( ob->query("weight"), 0, "重量必須為正，否則負重計算會出錯" );
}

void test_value(object ob)
{
	expect_true( pointerp(ob->query("value")), "value 應該是 ({ 數量, 幣別 }) 形式" );
}

void test_long(object ob)
{
	expect_string( ob->query("long"), "long 描述不可為空" );
}
