#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "altar key", "祭壇鑰匙" );
	add( "id", ({ "key" }) );
	set_short( "an altar key", "祭壇鑰匙" );
	set_long(
		"A long iron key.\n",
		"這是用來開啟通往祭壇鐵門的鑰匙。\n"
	);
	set( "unit", "把" );
	set( "to_lock", "HAWK_ALTAR_ENTRANCE" );
	set( "weight", 3 );
	set( "value", ({ 40, "silver" }) );
	set( "no_sale", 1 );
}
