#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Earth Plate","大地鎧甲" );
	add( "id", ({ "plate" }) );
	set_short( "大地鎧甲" );
	set_long(@LONG
	由大地之母力量保護的鎧甲，據說只要大地存
	在，就不會受損害。
LONG
	);
	set( "unit","件" );
	set( "weight",120 );
	set( "type","body" );
	set( "material","heavy_metal" );
	set( "armor_class",36 );
	set( "defense_bonus",3 );
	set( "value",({ 6400,"silver" }) );
}
