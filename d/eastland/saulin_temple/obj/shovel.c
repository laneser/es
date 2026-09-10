#include "../saulin_temple.h"

inherit WEAPON;

void create()
{
	set_name("Shovel", "方便鏟");
	add ("id",({ "shovel" }) );
	set_short("方便鏟");
	set_long(@C_LONG
一把鏟子，是方便後用來埋土的。可是它的鏟緣十分的鋒利，讓你不禁
懷疑它到底是工具還是武器。
C_LONG
	);
	set( "weapon_class", 20 );
	set( "type", "blunt" );
	set( "min_damage", 12 );
	set( "max_damage", 20 );
	set( "weight", 50 );
	set( "no_sale", 1);
	set( "value", ({ 50, "gold" }) );
	set( "unit", "把" );
}
