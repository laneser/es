#include <mudlib.h>
inherit WEAPON;
void create()
{
	set_name("Princess's fan","芭蕉扇");
	add ("id",({ "fan"}) );
        set_short("芭蕉扇");
	set_long(@C_LONG
一柄芭蕉葉形狀的扇子。扇子上鑲有明玉翡翠之類的物品，珠光寶氣亂顯一通。  
C_LONG
	);
	set( "unit", "柄" );
        setup_weapon("blunt", 25,13,22);
        set( "special_things",1);
	set( "weight", 80 );
	set( "value", ({ 1000, "silver" }) );
}

