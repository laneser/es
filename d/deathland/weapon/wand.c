#include "../echobomber.h"

inherit WEAPON;

void create()
{
	set_name("fire wand", "地火之杖");
	add ("id",({ "wand",}) );
	set_short("地火之杖");
	set_long(
        "這是一把能呼喚「火球」的魔杖，你隱約可以看見杖頭閃著幾絲火光。\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 25 );
	set( "type", "wand" );
	set( "min_damage", 10 );
	set( "max_damage", 18 );
	set( "weight", 60 );
	set( "value", ({ 200, "gold" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 15 );
	set( "max_charge", 15 );
	set( "special_damage_type", "fire" );
	set( "special_damage", 15 );
//	set( "special_msg", " launches a fireball, you are almost stunned!\n" );
	set( "special_c_msg", "發出一團火球,擊向你的身體而燃燒\n" );
}
