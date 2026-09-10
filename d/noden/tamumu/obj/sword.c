#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bastardsword", "巨劍" );
	add( "id", ({ "bastardsword", "sword" }) );
	set_short(  "火狼之劍" );
	set_long(@C_LONG
這是一把很大、非常大、大到你必須用兩隻手才能「拿」在手上的巨劍，
它的劍刃上刻有一頭火狼的標誌，看起來酷斃了！
C_LONG
               );
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weapon_class", 38 );
	set( "min_damage", 21 );
	set( "max_damage", 43 );
	set( "weight", 230 );
	set( "nosecond", 1 );
	set( "value", ({ 210, "gold" }) );
}
