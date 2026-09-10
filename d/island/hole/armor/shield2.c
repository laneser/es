#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Shield","戰神盾" );
	add( "id", ({ "shield" }) );
	set_short( "戰神盾" );
	set_long(@LONG
	這是戰神五種裝備中之戰神盾。
LONG
           );
	set( "unit","面" );
	set( "weight",100 );
	set( "type","shield" );
	set( "material","heavy_metal" );
	set( "armor_class",8 );
	set( "defense_bonus",8 );
	set( "special_defense",([ "fire":10,"cold":10 ]) );
	set( "value",({ 2710,"silver" }) );
//	set( "no_sale",1 );
}
