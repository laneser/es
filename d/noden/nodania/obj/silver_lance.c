#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "silver lance", "銀槍" );
	add( "id", ({ "lance" }) );
	set_short( "銀槍" );
	set_long(@CLONG
這是一把閃亮的銀色長槍，大部分擅於使用戳刺型武器的騎士們都喜歡
這樣的武器。
CLONG
	);
	set( "unit", "把" );
	set( "type", "thrusting" );
	set( "weapon_class", 30 );
	set( "min_damage", 17 );
	set( "max_damage", 37 );
	set( "weight", 150 );
	set( "value", ({ 1500, "silver" }) );
}
