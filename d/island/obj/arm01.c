#include "../island.h"

inherit ARMOR;
void create()
{
	set_name( "Titan Armbands","鈦合金臂環" );
	add( "id", ({ "arm","armbands" }) );
	set_short( "鈦合金臂環" );
	set_long(@LONG
	聖騎士專用的臂環，是用一種奇特的金屬打造而
	成的。雖然是金屬材質，但是卻不像一般金屬那
	麼笨重。
LONG
           );
	set( "unit","對" );
	set( "weight",45 );
	set( "type","arms" );
	set( "material","heavy_metal" );
	set( "armor_class",6 );
	set( "defense_bonus",3 );
	set( "special_defense",([ "fire":10 ]) );
	set( "value",({ 1175,"silver" }) );
}
