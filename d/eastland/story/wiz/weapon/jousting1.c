#include <mudlib.h>
inherit WEAPON;

void create()
{
	set_name("golden jousting","黃金槍");
	add ("id",({ "jousting"}) );
        set_short("黃金槍");
	set_long(@C_LONG
這是一把全身金黃色的長槍。黃金槍是「巫咸國」標準的武器，也只有「巫咸國」
才會用黃金來鑄造武器。
C_LONG
	);
	set( "unit", "把" );
        setup_weapon("jousting", 25,14,24);
	set( "weight", 150 );
	set( "value", ({ 1500, "silver" }) );
}

