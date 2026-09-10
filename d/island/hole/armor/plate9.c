#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Blood Plate","黑麵血甲" );
	add( "id", ({ "plate" }) );
	set_short( "黑麵血甲" );
	set_long(@LONG
	為了得到黑暗的加護，用黑血染成的鎧甲，是
	戰場上的不祥物之一。
LONG
           );
	set( "unit","件" );
	set( "weight",110 );
	set( "type","body" );
	set( "material","heavy_metal" );
	set( "armor_class",38 );
	set( "defense_bonus",3 );
	set( "value",({ 2250,"silver" }) );
}
