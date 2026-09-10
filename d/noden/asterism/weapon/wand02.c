#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "sleet wand", "冰晶杖" );
	add( "id", ({ "wand" }) );
	set_short( "冰晶杖" );
	set_long(
		"這是一把冰晶杖，如果你對魔法武器有研究的話，這個武器\n"
		"將會是不錯的選擇。\n"
	);
	set( "unit", "把" );
	set( "type", "wand" );
	set( "weapon_class", 23 );
	set( "min_damage", 14 );
	set( "max_damage", 22 );
	set( "power_on", 1);
	set( "weight", 40 );
	set( "value", ({ 1500, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 10 );
	set( "max_charge", 10 );
	set( "special_damage_type", "cold" );
	set( "special_damage", 35 );
	set( "special_c_msg", "從杖頭噴出一團冰暴！" );
}
