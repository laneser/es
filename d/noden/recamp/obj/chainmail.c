#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name( "chainmail", "鎧甲" );
	add( "id", ({ "chain", "mail" }) );
   set_short( "鎧甲" );
	set_long(
		"這件鎧甲上有不少被武器砍出來的痕跡，看起來它原來的主人一定\n"
		"身經百戰。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "heavy_metal");
	set( "armor_class", 12 );
    set( "special_defense",
           ([ "acid":1, "poison":1 ]) );
	
	set( "weight", 180 );
	set( "value", ({ 80, "silver" }) );
}
