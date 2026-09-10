#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "crimson amulet", "鮮紅色護身符" );
	add( "id", ({ "amulet" }) );
	set_short( "鮮紅色護身符" );
	set_long(
		"這是一個鮮紅色的圓形革囊，上面烙著一個三角形的標記。\n"
	);
	set( "type", "misc" );
	set( "material", "leather" );
	set( "armor_class", 0 );
	set( "defense_bonus", 8 );
    set( "special_defense",
           ([ "evil":5, "magic":5, "divine":-10 ]) );
    set( "extra_skills", ([ "target":10 ]) );       
	set( "weight", 10 );
	set( "value", ({ 840, "silver" }) );
	set( "no_sale", 1 );
}
