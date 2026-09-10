#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Thorny sword", "荊棘長劍" );
        add( "id",({ "sword", "longsword" }) );
        set_long(@LONG
這是一把顏色黝黑的長劍，上面纏滿了鐵刺，被打中的人一定痛不欲生吧。
LONG
        );
        set_short( "荊棘長劍" );
        set( "unit", "把");
	set( "weapon_class", 40 );
        set( "type", "longblade" );
	set( "min_damage", 17 );
        set( "max_damage", 40 );
        set( "nosecond",1);
        set( "weight", 210 );
        set( "value", ({ 10, "silver" }) );
        set( "bleeding",20);
}


