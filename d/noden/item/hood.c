#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name( "colorful hood", "花布頭巾" );
	add( "id", ({ "hood" }) );
   set_short( "花布頭巾" );
	set_long(
		"這條花布頭巾已經很破舊了，戴著它看起來一定很土。\n"
	);
	set( "unit", "條" );
	set( "type", "head" );
	set( "material", "cloth");
	set( "armor_class", 1 );
	set( "weight", 10 );
	set( "value", ({ 24, "silver" }) );
}
