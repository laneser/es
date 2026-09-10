#include <mudlib.h>

inherit WEAPON;

void create()
{
    set_name( "coral blade", "琅□寶刀" );
    add( "id", ({ "blade" }) );
    set_short( "琅□寶刀" );
	set_long(
        "這是一把用萬年金珊瑚打造而成的長刀, 通體金亮, 但刀刃中隱約透出\n"
        "一絲紅光, 似乎是因沾滿血腥所致。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 90 );
    set( "weapon_class", 30 );
    set( "min_damage", 15 );
    set( "max_damage", 28 );
//    set( "bleeding", 15 );
    set( "value", ({ 1200, "silver" }) );
}
