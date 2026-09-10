#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "flamming wand", "火焰杖" );
	add( "id", ({ "wand" }) );
	set_short( "火焰杖" );
	set_long(
		"這是一把火焰杖，如果你對這類型的魔法武器有研究的話，這種武器\n"
		"將會是不錯的選擇。\n"
	);
	set( "unit", "把" );
	set( "type", "wand" );
	set( "weapon_class", 13 );
	set( "min_damage", 4 );
	set( "max_damage", 10 );
	set( "weight", 50 );
	set( "value", ({ 680, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 5 );
	set( "max_charge", 5 );
	set( "special_damage_type", "fire" );
	set( "special_damage", 30 );
	set( "special_c_msg", "從杖頭冒出熊熊的火焰！" );
}

