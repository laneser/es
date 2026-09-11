#include "takeda.h"

inherit WEAPON;

void create()
{
	set_name("fishman's shortblade", "漁師短刀");
	add("id",({"shortblade"}));
	set_short("漁師短刀");
	set_long(
		"這是一把鋒利的短刀，漁夫多用它來防身或處理魚獲。\n"
	);
	set( "unit", "把" );
	set( "weight", 95 );
	set( "type", "shortblade" );
	set( "second",1);
	set( "weapon_class", 17 );
	set( "min_damage", 8 );
	set( "max_damage", 16 );
	set( "value", ({ 415, "silver" }) );
}
