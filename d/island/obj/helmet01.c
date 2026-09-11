#include "../island.h"

inherit ARMOR;
void create()
{
	set_name( "Titan Helmet","鈦合金覆面" );
	add( "id", ({ "helmet" }) );
	set_short( "鈦合金覆面" );
	set_long(@LONG
	聖騎士專用的頭盔，是用一種奇特的金屬打造而
	成的。雖然是金屬材質，但是卻不像一般金屬那
	麼笨重。
LONG
           );
	set( "unit","件" );
	set( "weight",50 );
	set( "type","head" );
	set( "material","heavy_metal" );
	set( "armor_class",10 );
	set( "defense_bonus",1 );
	set( "special_defense",([ "fire":5 ]) );
	set( "value",({ 1370,"silver" }) );
}
