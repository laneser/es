#include "../hole.h"

inherit ARMOR;
void create()
{
	set_name( "Silver Cloak","銀絲披風" );
	add( "id",({ "cloak" }) );
	set_short( "銀絲披風" );
	set_long(@LONG
	傳說中龍騎士身上所披的摩登披風。
LONG
           );
	set( "unit","件" );
	set( "weight",40 );
	set( "type","cloak" );
	set( "material","knight" );
	set( "armor_class",6 );
	set( "defense_bonus",4 );
	set( "special_defense",([ "fire":30,"cold":-10,"none":15 ]) );
	set( "value",({ 1170,"silver" }) );
}
