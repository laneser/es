#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black hat", "捕快帽" );
	add( "id", ({ "hat","cap" }) );
	set_short( "a black hat", "捕快帽" );
	set_long(
		"You see policeman's black hat.\n",
		"這是一頂捕快們的制式帽子，上面還插了根羽毛。\n"
	);
	set( "unit", "頂" );
	set( "type", "head" );
        set("material","cloth");
	set( "weight", 60 );
	set( "armor_class", 3 );
	set( "value", ({ 120, "silver" }) );
}
