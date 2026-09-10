#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "small cap", "瓜皮小帽" );
	add( "id", ({ "cap" }) );
	set_short( "a small cap", "瓜皮小帽" );
	set_long(
		"You see a small round cap.\n",
		"這是一頂綢緞布面的圓頂小帽，看起來像是有錢人的帽子。\n"
	);
	set( "unit", "頂" );
        set("material","leather");
	set( "type", "head" );
	set( "armor_class", 4 );
	set( "weight", 20 );
	set( "value", ({ 70, "silver" }) );
}
