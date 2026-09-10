
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "moon sword", "名刀月殘" );
        add( "id",({ "moon","sword" }) );
        set_short( "moon sword", "名刀月殘" );
        set_long(@AAA
            這是一把有名的月殘刀，據說這是因為鑄劍師做好這把劍時
            剛好看到月蝕而命名，和星落刀是一對雙劍
AAA
);
        set( "unit", "把");
        set( "weapon_class", 35 );
//        set( "bleeding", 15 );
        set( "type", "longblade" );
        set( "min_damage", 15 );
        set( "max_damage", 40 );
        set( "weight", 140 );
        set( "value", ({ 920, "silver" }) );
}



