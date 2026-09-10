#include "takeda.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("snake_polearm","丈八蛇矛");
       add("id",({"polearm","snake polearm",}) );
       set_short("丈八蛇矛");
	   set_long(
           "這是一把長的嚇死人的怪矛，矛身彎彎曲曲，就像一條扭曲的蛇．\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 45 );
        set("type","polearm");
	set( "min_damage", 30 );
	set( "max_damage", 44 );
	set( "weight", 180 );
	set( "value", ({ 440, "gold" }) );
        set("nosecond",1);
}

