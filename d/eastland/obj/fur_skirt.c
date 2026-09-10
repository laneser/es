#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "fur skirt", "獸皮裙子" );
	add( "id", ({ "skirt" }) );
   set_short( "獸皮裙子" );
	set_long(
		"這是一件骯髒的獸皮裙子，上面的毛皮東掉一塊，西禿一塊，十分難看。\n"
	);
	set( "unit", "件" );
	set( "type", "legs" );
	set( "material", "leather" );
	set( "weight", 60 );
	set( "armor_class", 3 );
	set( "defense_bonus", 1 );
	set( "special_defense", ([ "fire":-2, "cold":1 ]) );	
	set( "value", ({ 170, "silver" }) );
}
