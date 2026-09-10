#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name( "wooden club", "木棒" );
	add( "id", ({ "club" }) );
   set_short( "木棒" );
	set_long(
		"一根看起來沒有什麼特別的木棒，握柄部份用布條纏了幾圈。\n"
	);
	set( "unit", "根" );
	set( "type", "blunt" );
	set( "weapon_class", 3 );
	set( "min_damage", 2 );
	set( "max_damage", 6 );
	set( "weight", 60 );
	set( "value", ({ 10, "silver" }) );
}
