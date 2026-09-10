#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bastardsword", "闊劍" );
	set_short( "銀色闊劍" );
	set_long(@CLONG
這是一把巨大、閃亮的銀色闊劍，它看起來又重又銳利，只有精通劍術和
力量強大的人能駕馭這樣的武器。
CLONG
	);
	set( "unit", "把" );
	set( "weapon_class", 32 );
	set( "type", "longblade" );
	set( "min_damage", 17 );
	set( "max_damage", 38 );
	set( "nosecond", 1 );
	set( "weight", 180 );
	set( "value", ({ 1400, "silver" }) );
}
