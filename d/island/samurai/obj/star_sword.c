
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "star sword", "名刀星落" );
        add( "id",({ "star","sword" }) );
        set_short( "star sword", "名刀星落" );
        set_long(@AAA
            這是一把有名的星落刀，據說這是因為鑄劍師做好這把劍時
            剛好看到流星而命名
AAA
);
        set( "unit", "把");
        set( "weapon_class", 30 );
//        set( "bleeding", 15 );
        set( "type", "longblade" );
        set( "min_damage", 15 );
        set( "max_damage", 30 );
        set( "weight", 140 );
        set( "value", ({ 920, "silver" }) );
}



