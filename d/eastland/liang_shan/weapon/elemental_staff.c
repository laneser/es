#include "takeda.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("elemental staff","水火風雷棍");
       add("id",({"staff"}) );
       set_short("水火風雷棍");
	   set_long(
           "一把斑剝的古代木棍，看來破破爛爛，你懷疑它還能當武器使用．\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 35 );
        set("type","blunt");
	set( "min_damage", 15 );
	set( "max_damage", 38 );
	set( "weight", 110 );
	set( "value", ({ 501, "gold" }) );
        set("special_damage",30);
}

