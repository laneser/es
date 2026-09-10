#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "flamming wand", "火焰杖" );
	add( "id", ({ "wand" }) );
	set_short( "火焰杖" );
	set_long(@CLONG
    這是一把火焰杖，如果你對這類型的魔法武器有研究的話，這種武器
將會是不錯的選擇。
CLONG
	);
	set( "unit", "把" );
	set( "type", "wand" );
	set( "weapon_class", 13 );
	set( "min_damage", 7 );
	set( "max_damage", 14 );
	set( "weight", 50 );
	set( "value", ({ 680, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 6 );
	set( "max_charge", 6 );
	set( "power_on", 1);
	set( "special_damage_type", "fire" );
	set( "special_damage", 30 );
	set( "special_c_msg", "從杖頭冒出熊熊的火焰！" );
}

