#include "../echobomber.h"

inherit WEAPON;

void create()
{
   // seteuid(getuid());
	set_name("long spear of Wind", "風之長矛");
	add ("id",({ "spear" }) );
	set_short("風之長矛");
	set_long(
            "一把曾在戰爭中發揮極大功能的長矛,它能夠隨著風向刺入敵人的心臟\n"
	);
	set( "unit", "把" );
	set( "weapon_class", 25 );
	set( "type", "thrusting" );
	set( "min_damage", 10 );
	set( "max_damage", 23 );
	set( "weight", 190 );
	set( "value", ({ 2220, "silver" }) );
}

