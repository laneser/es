#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("mahogany axe","盤古之斧");
	add ("id",({ "axe"}) );
        set_short("盤古之斧");
	set_long(@C_LONG
一把古老的青銅鑄桃木握把小斧，對降妖伏魔有其獨特之處。	
C_LONG
	);
	set( "unit", "把" );
        setup_weapon("axe", 25,18,25);
	set( "weight", 150 );
	set( "value", ({ 1430, "silver" }) );
}

