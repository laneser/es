#include "../island.h"

inherit ARMOR;
void create()
{
	set_name( "Titan Boots","鈦合金戰靴" );
	add( "id", ({ "boots" }) );
	set_short( "鈦合金戰靴" );
	set_long(@LONG
	聖騎士專用的戰靴，是用一種奇特的金屬打造而
	成的。雖然是金屬材質，但是卻不像一般金屬那
	麼笨重。
LONG
           );
	set( "unit","雙" );
	set( "weight",30 );
	set( "type","feet" );
	set( "material","heavy_metal" );
	set( "armor_class",10 );
	set( "defense_bonus",2 );
	set( "special_defense",([ "fire":10 ]) );
	set( "value",({ 2780,"silver" }) );
}
