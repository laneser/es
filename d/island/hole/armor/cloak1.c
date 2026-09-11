#include "../hole.h"

inherit ARMOR;
void create()
{
	set_name( "Cloak","戰神披風" );
	add( "id",({ "cloak" }) );
	set_short( "戰神披風" );
	set_long(@LONG
	這是戰神五種配備中的披風。
LONG
           );
	set( "unit","件" );
	set( "weight",50 );
	set( "type","cloak" );
	set( "material","leather" );
	set( "armor_class",8 );
	set( "defense_bonus",4 );
	set( "special_defense",([ "fire":25,"cold":10,"none":15 ]) );
	set( "value",({ 5700,"silver" }) );
//	set( "no_sale",1 );
}
