
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "lakonia sword", "拉克尼安劍" );
        add( "id",({ "sword" }) );
        set_short( "lakonia sword", "拉克尼安劍" );
        set_long(@AAA
這是一把用拉克尼安金屬所造的長劍
AAA
        );
        set( "unit", "把");
        set( "weapon_class", 26 );
        set( "type", "longblade" );
//        set( "bleeding", 15 );
        set( "min_damage", 13 );
        set( "max_damage", 26 );
        set( "weight", 150 );
        set( "value", ({ 620, "silver" }) );
}



