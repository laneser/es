#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name( "wooden shield", "木盾" );
	add( "id", ({ "shield"  }) );
   set_short( "木盾" );
	set_long(
		"一面堅硬的木製盾牌，上面畫了一隻張牙舞爪的火龍。\n"
	);
	set( "unit", "面" );
	set( "type", "shield" );
	set( "material", "wood" );
	set( "weight", 60 );
	set( "armor_class", 3 );
	set( "value", ({ 60, "silver" }) );
}
