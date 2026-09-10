#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "highsteel halberd", "長戈" );
	add( "id", ({ "halberd" }) );
	set_short( "青鋼長戈" );
	set_long("這是一把質地堅硬，青鋼鑄成的長戈。\n");
	set( "unit", "把" );
	set( "weight", 190 );
	setup_weapon( "polearm", 30, 17, 34 );
	set( "bleeding", 10 );
	set( "nosecond", 1 );
	set( "value", ({ 1420, "silver" }) );
}
