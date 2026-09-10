#include "../saulin_temple.h"

inherit WEAPON;

void create()
{
   set_name("Club","齊眉棍");
   add("id",({ "staff", }) );
   set_short("齊眉棍");
   set_long(
       "少林僧常用的□制的齊眉棍。\n"
   	);
	set( "unit", "條" );
 	set( "weapon_class", 10 );
	set( "type", "bo");
	set( "min_damage", 8 );
	set( "max_damage", 15 );
	set( "weight", 45 );
	set( "value", ({ 250, "silver" }) );
}
