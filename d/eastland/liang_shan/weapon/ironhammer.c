#include "takeda.h"

inherit WEAPON;

void create()
{
	set_name("iron hammer", "鐵瓜□");
	add("id",({"hammer"}));
	set_short("鐵瓜□");
	set_long(
		"這把鐵□特地做成瓜的形狀，使用時風阻可能較小。\n"
	);
	set( "unit", "把" );
	set( "weight", 130 );
	set( "type", "blunt" );
	set( "weapon_class", 18 );
	set( "min_damage", 10 );
	set( "max_damage", 20 );
	set( "value", ({ 530, "silver" }) );
}
