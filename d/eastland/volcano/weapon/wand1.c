#include "../oldcat.h"

inherit WEAPON;

void create()
{
	set_name("storm wand", "狂風杖");
	add ("id",({ "wand",}) );
	set_short("狂風杖");
	set_long(
        "這是一把能呼喚「風暴」的魔杖，你隱約可以看見杖頭附近的空氣有些擾動。\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 35 );
	set( "type", "wand" );
        set( "min_damage", 17 );
	set( "max_damage", 30 );
	set( "weight", 50 );
	set( "power_on", 1);
	set( "no_sale", 1);
	set( "value", ({ 5000, "silver" }) );

	set( "hit_func", "wand_hit" );
	set( "charge_left", 8 );
	set( "max_charge", 8 );
	set( "special_damage_type", "energy" );
	set( "special_damage", 80 );
	set( "special_c_msg", "招來一陣風暴，使所有的敵人皆陷入風暴之中。\n" );
}
