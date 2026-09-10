#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("darkgreen cloak", "黑綠羅襖");
        add( "id", ({ "cloak","cape" }) );
        set_short("darkgreen cloak","黑綠羅襖");
        set_long(
                "This is darkgreen cloak. \n",
                "一件暗綠色的鬥蓬，上面繡著金色的麒麟．\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 5 );
        set( "defense_bonus", 4 );
        set( "special_defense",(["none":1,"divine":1,"evil":2 ]) );
        set( "weight", 70 );
        set( "value", ({ 490, "silver" }) );
}