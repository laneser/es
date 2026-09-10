#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("Rain amulet","雨符");
        add("id",({"amulet"}) );
        set_short("雨符");
	set_long(@C_LONG
一個雨師精製的護符，上繪水滴的形狀，整個看上去好似浸在水裡一樣。
C_LONG	         );
	set( "unit", "個" );
	set( "weight",6 );
	set( "type", "misc" );
        set("material","cloth");
	set( "defense_bonus", 4 );
	set( "special_defense",(["evil":20,"divine":-15]));
	set( "value", ({ 1000, "silver" }) );
}
