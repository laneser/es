#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
        set_name( "staff", "刺杖" );
	add( "id", ({ "staff" }) );
   set_short( "刺杖" );
	set_long(
		"這根木杖上面釘滿了尖尖的鐵刺，有些刺上還帶有倒鉤。\n"
	);
	set( "unit", "根" );
	set( "type", "blunt" );
	set( "weapon_class", 9 );
	set( "min_damage", 3 );
	set( "max_damage", 10 );
	set( "weight", 70 );
	set( "value", ({ 40, "silver" }) );
}
