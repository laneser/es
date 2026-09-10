#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "hell wand", "冥淵杖" );
	add( "id", ({ "wand" }) );
	set_short( "冥淵杖" );
	set_long(
"這是一把黑色又老舊的魔杖，杖柄上依稀雕著一個夜叉的頭像。\n"
	);
	set( "unit", "把" );
	set( "type", "wand" );
	set( "weapon_class", 30 );
	set( "min_damage", 8 );
	set( "max_damage", 15 );
	set( "weight", 55 );
	set( "value", ({ 1000, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 10 );
	set( "max_charge", 10 );
	set( "special_damage_type", "cold" );
	set( "special_damage", 45+random(10));
	set( "special_c_msg",
 "從杖頭湧出一股酷寒的陰風，你看到它噴到的地方都結冰了！" );
}

