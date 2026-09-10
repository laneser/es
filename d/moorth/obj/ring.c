#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "crystal ring", "水晶戒指" );
	add( "id", ({ "ring" }) );
	set_short( "a crystal ring", "水晶戒指" );
	set_long(
		"You see a crystal ring. It is glowing in a soft aura.\n",
		"這個水晶戒指上面鑲著一粒鮮紅色的水晶，水晶周圍似乎圍繞著一\n"
		"圈水氣，被水晶內部發出的微光照得朦朦朧朧。\n"
	);
	set( "type", "finger" );
	set( "material", "element" );
	set( "defense_bonus", 5 );
	set( "special_defense", ([ "energy":5, "electric":-8 ]) );
	set( "weight", 3 );
	set( "value", ({ 1840, "silver" }) );
}
