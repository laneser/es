#include "../island.h"

inherit ARMOR;
void create()
{
	set_name( "Titan Gauntlets","鈦合金護手" );
	add( "id", ({ "gauntlets","gloves" }) );
	set_short( "鈦合金護手" );
	set_long(@LONG
	聖騎士專用的護手，是用一種奇特的金屬打造而
	成的。雖然是金屬材質，但是卻不像一般金屬那
	麼笨重。
LONG
           );
	set( "unit","雙" );
	set( "weight",20 );
	set( "type","hands" );
	set( "material","heavy_metal" );
	set( "armor_class",5 );
	set( "defense_bonus",5 );
	set( "special_defense",([ "fire":10 ]) );
	set( "value",({ 2890,"silver" }) );
}
