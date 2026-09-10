#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "dragon shield", "龍鱗盾" );
	add( "id", ({ "shield" }) );
	set_short(  "龍鱗盾" );
	set_long( @C_LONG
整個盾就像一顆龍頭, 張牙裂嘴, 栩栩如生. 閃著耀眼的金光, 價值一定不低.
C_LONG
	);
	set( "unit", "面" );
	set( "type", "shield" );
	set( "material", "heavy_metal");
	set( "armor_class", 9 );
	set( "defense_bonus", 2);
	set( "special_defense",
	     ([ "none":5, "mental":-5 ]) );
	set( "extra_skills",([ "block":7 ]) );     
	set( "weight", 150 );
	set( "no_sale", 1);
	set( "value", ({ 5970, "silver" }) );
}
