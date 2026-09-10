#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "holyword wand", "聖言杖" );
	add( "id", ({ "wand" }) );
	set_short( "聖言杖" );
	set_long(
		"這是一把黝黑的法杖，上面還刻繪有許多奇特的符號。\n"
	);
	set( "unit", "把" );
	set( "type", "wand" );
	set( "weapon_class", 35 );
	set( "min_damage", 8 );
	set( "max_damage", 14 );
	set( "weight", 70 );
	set( "value", ({ 2000, "silver" }) );
	set( "hit_func", "wand_hit" );
	set( "charge_left", 10 );
	set( "max_charge", 10 );
	set( "special_damage_type", "divine" );
	set( "special_damage", 40 );
	set( "special_c_msg", "從杖頭發出一道金色的光芒 !!\n"+
	    "你看到各種真言、佛號在空中飛舞 !!\n" );
}

