#include <mudlib.h>
inherit WEAPON;

void create()
{
	set_name("golden polearm","黃金長矛");
	add ("id",({ "polearm"}) );
        set_short("黃金長矛");
	set_long(@C_LONG
這是一把全身金黃色的長矛。雖然拿起來很沈重，前端矛頭卻異常鋒利，不失為一
把好武器。  
C_LONG
	);
	set( "unit", "把" );
        setup_weapon("polearm", 30,19,30);
	set( "weight", 150 );
	set( "value", ({ 1000, "silver" }) );
}

