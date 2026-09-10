#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "worn skirt", "舊裙子" );
	seteuid(getuid());
	add( "id", ({ "skirt" }) );
   set_short( "舊裙子" );
	set_long(
		"這件裙子已經又破又舊了，但是看起來仍然很乾淨。\n"
	);
	set( "unit", "件" );
	set( "type", "legs" );
	set( "material", "cloth");
	set( "armor_class", 2 );
	set( "weight", 30 );
	set( "value", ({ 13, "silver" }) );
}
