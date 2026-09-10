#include <../island.h>

inherit ARMOR;
void create()
{
	set_name( "Titan Shield","鈦合金盾" );
	add( "id", ({ "shield" }) );
	set_short( "鈦合金盾" );
	set_long(@LONG
	聖騎士專用的盾牌，是用一種奇特的金屬打造而
	成的。雖然是金屬材質，但是卻不像一般金屬那
	麼笨重。
LONG
           );
	set( "unit","面" );
	set( "weight",60 );
	set( "type","shield" );
	set( "material","heavy_metal" );
	set( "armor_class",10 );
	set( "defense_bonus",5 );
	set( "special_defense",([ "fire":10 ]) );
	set( "value",({ 3125,"silver" }) );
}
