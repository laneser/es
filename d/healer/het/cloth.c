#include <mudlib.h>
inherit ARMOR;
void create()
{
	seteuid(getuid());
	set_name("night cloth","夜行服");
	add("id",({"cloth"}));
	set_short("夜行服");
	set_long(@LONG
這是一件輕便的深色衣服, 使小偷在夜間活動時能輕易的隱藏自己。
衣服上有許多口袋, 可以放小刀, 萬能鎖, 鐵絲等小巧的工具。
LONG
	);
	set("unit","件");
	set("weight",40);
	set("type","body");
	set("material","thief");
	set("armor_class",15);
	set("defense_bonus",5);
	set("value",960);
}
