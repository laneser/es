#include "../almuhara.h"

inherit WEAPON;

void create()
{
    set_name("Famous Sword", "名劍" );
    add("id", ({"sword","famous sword"}) );
    set_short("名劍「長歌」");
	set_long(
           "一把非常有名的長劍，在劍鍔處鑄了兩個小字  --- 「長歌」\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 33 );
        set( "type","longblade");
	set( "min_damage", 20 );
	set( "max_damage", 35 );
	set( "weight", 90 );
	set( "value", ({ 240, "gold" }) );
}

