#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bronze claws", "青銅爪" );
	add( "id", ({ "claw", "claws" }) );
   set_short( "青銅爪" );
	set_long(
		"這是一雙沾滿暗紅色血跡的青銅爪，看起來相當重。\n"
	);
	set( "unit", "雙" );
	set( "second", 1 );
	setup_weapon( "unarmed", 22, 13, 17 );
	set( "bleeding", 15 );
	set( "weight", 140 );
	set( "value", ({ 470, "silver" }) );
	set_c_verbs( ({ "用%s往%s一抓", "%s劃出一道暗紅的血光，掃過%s",
		"的%s「刷」的一聲，往%s劃去" }) );
}
