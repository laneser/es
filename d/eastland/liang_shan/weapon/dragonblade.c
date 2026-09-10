#include "takeda.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("green-dragon glaive ","青龍偃月刀");
       add("id",({"glaive","green-dragon",}) );
       set_short("青龍偃月刀");
	   set_long(@C_LONG
這是武聖關公所用的青龍偃月刀，破壞力相當大，但沒有過人的力量
是拿不動的
C_LONG	);
	
	set( "unit", "把" );
 	set( "weapon_class", 48 );
        set("type","longblade");
	set( "min_damage", 30 );
	set( "max_damage", 53 );
	set( "weight", 250 );
	set( "nosecond", 1 );
        set( "bleeding",10);
	set( "value", ({ 1010, "gold" }) );
}

