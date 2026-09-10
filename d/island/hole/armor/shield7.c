#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Fire Scale Shield","火麟盾" );
	add( "id", ({ "shield" }) );
	set_short( "火麟盾" );
	set_long(@LONG
	這是一面用材質較輕的金屬打造的盾，上面一
	共鑲了五片火麒麟的鱗片。
LONG
           );
	set( "unit","面" );
	set( "weight",100 );
	set( "type","shield" );
	set( "material","heavy_metal" );
	set( "armor_class",8 );
	set( "defense_bonus",3 );
	set( "special_defense",([ "fire":30,"cold":10 ]) );
	set( "value",({ 1440,"silver" }) );
//	set( "no_sale",1 );
}
