#include "takeda.h"

inherit WEAPON;

void create()
{
       set_name("two-faced blade","三尖兩刃刀");
       add("id",({"blade"}) );
       set_short("三尖兩刃刀");
	   set_long(
           "這是一把造形奇特的寶刀，刀尖部有三個分叉，似乎可用來格開武器．\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 25 );
    set("type","longblade");
	set( "min_damage", 13 );
	set( "max_damage", 26 );
	set("bleeding",5);
	set( "value", ({ 62, "gold" }) );
	set( "extra_skills",(["parry":10]));
	
}	
