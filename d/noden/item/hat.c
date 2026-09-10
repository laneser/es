#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name( "worn hat", "舊帽子" );
	add( "id", ({ "hat" }) );
   set_short( "舊帽子" );
	set_long(
		"這頂帽子已經很破舊了，上面有好幾個破洞。\n"
	);
	set( "unit", "頂" );
	set( "type", "head" );
	set( "material","cloth");
	set( "armor_class", 1 );
	set( "weight", 10 );
	set( "value", ({ 15, "silver" }) );
}
