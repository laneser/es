#include <mudlib.h>

inherit WEAPON;

void create()
{
    set_name( "cleaver", "屠刀" );
    set_short( "屠刀" );
	set_long(
        "這是一把十分黝黑的巨刀, 令你十分懷疑有誰能使動此刀?\n"
	);
    set( "unit", "把" );
    setup_weapon( "longblade", 20, 10, 25 );
    set( "weight", 350 );
    set( "value", ({ 3, "silver" }) );
}
