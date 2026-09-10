#include "mudlib.h"

inherit WEAPON;

void create()
{
       set_name("tail of scorpion","蠍子尾巴");
       add("id",({"whip","tail",}) );
       set_short("蠍子尾巴");
	   set_long(
	   "這是一隻蠍子的尾巴，末端生著銳利的倒刺，也許你可以拿來當武器...\n"
	);
	
	set( "unit", "條" );
 	set( "weapon_class", 25 );
        set("type","whip");
	set( "min_damage", 10 );
	set( "max_damage", 30 );
	set( "weight", 10 );
        set( "value", ({ 1, "silver" }) );
        set( "no_sale", 1 );
    set_c_verbs(({
    "%s揮出一股腥風，打向%s",
    "%s隨手一揮，倒刺打向%s",
    "%s高高舉起，由空中如蛇般筆直襲向%s",}));
}

