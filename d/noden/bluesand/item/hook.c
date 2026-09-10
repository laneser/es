#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "steel hook", "鋼鉤" );
	add( "id", ({ "hook" }) );
   set_short( "鋼鉤" );
	set_long(
		"這個鋼鉤上有一個保護手部的鐵套，不知道為什麼海盜都喜歡用這種武器？\n"
	);
	set( "unit", "把" );
	setup_weapon( "unarmed", 21, 9, 28 );
	set( "weight", 50 );
	set( "value", ({ 940, "silver" }) );
}
