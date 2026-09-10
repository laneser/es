#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name("headband", "必勝頭巾");
	set_short("必勝頭巾");
	set_long(
		"這是一條白色頭巾，上面寫著「必勝」。\n"
	);
	set( "unit", "條" );
	set( "type", "head" );
	set( "armor_class", 3 );
	set( "defense_bonus", 5 );
	set( "value", ({ 3100, "gold" }) );
	set( "weight", 40 );
	set( "no_sale", 1);
}
