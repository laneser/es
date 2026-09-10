#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Bronze Plate","青銅鎧甲" );
	add( "id", ({ "plate" }) );
	set_short( "青銅鎧甲" );
	set_long(@LONG
	這是一件用青銅片編成的戰甲，雖然稍微笨重
	一些，但它可是保命的好東西喔。
LONG
           );
	set( "unit","件" );
	set( "weight",220 );
	set( "type","body" );
	set( "material","heavy_metal" );
	set( "armor_class",30 );
	set( "defense_bonus",3 );
	set( "value",({ 1440,"silver" }) );
}
