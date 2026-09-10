#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "looter's dagger", "匕首" );
	add( "id", ({ "dagger" }) );
   set_short( "盜墓者匕首" );
	set_long(
    "這是一把長而鋒利的匕首，在柄的末端還有許多鉤子，盜墓者通常用這種\n"
		"匕首挖取石棺或雕像上的寶石。\n"
	);
	set( "unit", "把" );
	set( "type", "dagger" );
	set( "weight", 40 );
	set( "weapon_class", 14 );
	set( "min_damage", 6 );
	set( "max_damage", 11 );
	set( "second", 1 );
	set( "value", ({ 420, "silver" }) );
}
