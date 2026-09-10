#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("green cloak", "鸚哥綠□絲戰袍");
        add( "id", ({ "cloak","cape" }) );
        set_short("green cloak","鸚哥綠□絲戰袍");
        set_long(
                "This is a green cloak with some floral mark.\n",
                "一件雙層湖綠的披風，繡了許多美麗的花紋．\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "weight", 100 );
        set( "value", ({ 1100, "silver" }) );
}