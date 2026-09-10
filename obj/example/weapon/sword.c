#include <mudlib.h>

inherit WEAPON ;

void create()
{
	set_name("long sword", "長劍");
	add ("id", ({ "sword" }) );
	set_short( "a long sword", "長劍");
	set_long(
		"It has a steel blade which is very sharp.\n",
		"這把長劍有十分鋒利的劍鋒。\n"
	);
	set( "weight", 40 );
	set( "weapon_class", 7 );
	set( "type", "shortblade" );
	set( "min_damage", 4 );
	set( "max_damage", 7 );
	set ("value", ({ 12, "gold" }) );
}
