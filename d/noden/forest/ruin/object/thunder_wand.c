#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("thunder wand", "幻雷杖");
	add ("id",({ "wand",}) );
	set_short("幻雷杖");
	set_long(
        "這是一把能呼喚「幻雷」的魔杖，你隱約可以看見杖頭閃著幾絲電光。\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 39 );
	set( "type", "wand" );
	set( "min_damage", 20 );
	set( "max_damage", 30 );
	set( "weight", 50 );
	set( "power_on", 1);
	set( "no_sale", 1);
	set( "value", ({ 9000, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 8 );
	set( "max_charge", 8 );
	set( "special_damage_type", "electric" );
	set( "special_damage", 80 );
	set( "special_c_msg", "發出一股強大的電殛，震得在場所有人全身發麻！" );
}
