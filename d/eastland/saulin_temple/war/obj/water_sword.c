#include "mudlib.h"

inherit WEAPON;

void create()
{
        set_name("ice sting","冰刺");
        add("id",({"sting"}) );
       set_short("冰刺");
       set_long(
         "這是用冰晶製成的鋒利短刃兵器，透明的鋒刃顯得不比尋常。\n");

        set( "unit", "把" );
        set( "weapon_class", 14 );
	set("type","shortblade");
        set( "min_damage", 8 );
        set( "max_damage", 16 );
	set( "weight", 80 );
        set( "value", ({ 540, "silver" }) );
}
