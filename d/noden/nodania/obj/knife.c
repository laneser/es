#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("knife", "小刀");
	set_short("生鏽的青銅小刀");
	set_long(@CLONG
一把生滿銅綠的青銅小刀，這把小刀也許是價值連城的古董，但是拿
來當武器未免....。
CLONG
      	       );
	set( "weight", 50 );
	set( "type", "dagger" );
	set( "weapon_class", 6 );
	set( "min_damage", 5 );
	set( "max_damage", 14 );
	set( "second", 1 );
	set( "value", ({ 150, "gold" }) );
}
