#include <mudlib.h>
inherit WEAPON;

void create()
{
	set_name("golden pen","金筆");
	add ("id",({ "pen"}) );
        set_short("金筆");
	set_long(@C_LONG
一枝純金打造的筆管，毛沾金墨，昂貴極了。
C_LONG
	);
	set( "unit", "枝" );
        setup_weapon("thrusting", 30,15,20);
	set( "weight", 100 );
        set("second",1);
        set( "special_things",1);
	set( "value", ({ 2500, "silver" }) );
}

