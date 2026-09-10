#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "wind_blade_sword", "風刃劍" );
        add( "id",({ "blade","sword" }) );
        set_short( "wind_blade_sword", "風刃劍" );
        set_long(@AAA
這是一把鋒利的長劍，是武士團的制式武器，由於其製造金屬特殊
使得這把劍比起普通的劍來可以造成較多傷害
AAA
     );
        set( "unit", "把");
//        set("bleeding", 10 );
        set("nosecond", 1 );
        set( "weapon_class", 27 );
        set( "type", "longblade" );
        set( "min_damage", 15 );
        set( "max_damage", 30 );
        set( "weight", 180 );
        set( "value", ({ 820, "silver" }) );
}



