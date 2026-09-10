#include "../almuhara.h"

inherit WEAPON;

void create()
{
    set_name("Antique Sword", "古劍" );
    add("id", ({"sword"}) );
    set_short("古劍「蒼松」");
	set_long(
           "一把造型古意盎然的長劍，在劍鍔處鑄了兩個小字  --- 「蒼松」\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 32 );
        set( "type","longblade");
	set( "min_damage", 20 );
	set( "max_damage", 34 );
	set( "weight", 90 );
	set( "value", ({ 250, "gold" }) );
}

