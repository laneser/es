#include "takeda.h"

inherit ARMOR;

void create()
{
        set_name("ruby ring","紅寶石戒指");
        add("id",({"ring"}) );
         set_short( "ruby ring","紅寶石戒指");
	set_long(
"這是由紅寶石所製成的美麗戒子，看來價值不菲....\n"
);
	set( "unit", "個" );
	set( "weight", 10 );
	set( "type", "finger" );
	set( "material","element");
	set( "defense_bonus", 5 );
	set( "equip_func","equip_ring");
	set( "value", ({ 880, "silver" }) );
        set("extra_skills",(["dodge":-5,"unarmed":-10]));
}
void equip_ring()
{
object holder;
    holder=this_player();
    tell_room(environment(holder),
    holder->query("c_name")+"套上一隻亮麗的紅寶石戒指....\n"
    ,({holder}));
    tell_object(holder,
    "你小心翼翼的套上紅寶石戒指....\n");
return ;
}