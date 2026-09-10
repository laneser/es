#include "../almuhara.h"

inherit WEAPON;

void create()
{
    set_name("Gemmy Sword", "寶劍" );
    add("id", ({"sword","gemmy sword"}) );
    set_short("寶劍「屠刀」");
	set_long(
           "一把寶光燦爛的長劍，在劍鍔處鑄了兩個小字  --- 「屠刀」\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 34 );
        set( "type","longblade");
	set( "min_damage", 20 );
	set( "max_damage", 33 );
	set( "weight", 90 );
	set( "value", ({ 280, "gold" }) );
}

