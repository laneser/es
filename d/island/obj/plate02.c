#include "../island.h"

inherit ARMOR;
void create()
{
	set_name( "Titan Chainmail","鈦合金鎧甲" );
	add( "id", ({ "chainmail","mail" }) );
	set_short( "鈦合金鎧甲" );
	set_long(@LONG
	聖騎士專用的鎧甲，是用一種奇特的金屬打造而
	成的。雖然是金屬材質，但是卻不像一般金屬那
	麼笨重。
LONG
           );
	set( "unit","件" );
	set( "weight",100 );
	set( "type","body" );
	set( "material","heavy_metal" );
	set( "armor_class",40 );
	set( "defense_bonus",5 );
	set( "special_defence",([ "fire":10 ]) );
	set( "value",({ 2670,"silver" }) );
}
