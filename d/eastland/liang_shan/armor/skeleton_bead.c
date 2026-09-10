#include "takeda.h"

inherit ARMOR;

void create()
{
        set_name("skeleton beads","人頂骨數珠");
        add("id",({"skeleton","beads"}) );
         set_short( "a skeleton beads","人頂骨數珠");
	set_long(
"This is a chain of beads make of skeleton . \n"
"由人頂骨做成的大數珠，共有十八粒，隱隱發出令人作嘔的血腥氣．\n"
);
	set( "unit", "個" );
	set( "weight", 100 );
	set( "type", "misc" );
	set( "material","stone");
        set( "defense_bonus", 7 );
	set( "no_sale",1);
	set( "value", ({ 250, "gold" }) );
        set( "special_defense",(["evil":-5 ,"divine":7]));
        set( "extra_stats",(["pie":-2]));
}
