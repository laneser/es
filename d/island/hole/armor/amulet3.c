#include "../hole.h"

inherit ARMOR;
void create()
{
	set_name( "Dragon bone","龍骨" );
	add( "id", ({ "bone" }) );
	set_short( "龍骨" );
	set_long(@LONG
	據說是龍身上最重要的一塊骨頭，有神聖力量
	保護。
LONG
           );
	set( "unit","塊" );
	set( "weight",5 );
	set( "type","misc" );
	set( "material","element" );
	set( "defense_bonus",6 );
	set( "special_defense",([ "fire":10 ]) );
	set( "value",({ 2620,"silver" }) );
}
