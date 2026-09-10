#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("blue cloak", "青錦襖");
        add( "id", ({ "cloak","cape" }) );
        set_short("blue cloak","青錦襖");
        set_long(
                "This is blue cloak. \n",
                "一件藍緞子做的花袍，這種衣服滿街都是．\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 4 );
        set( "defense_bonus", 3 );
        set( "weight", 70 );
        set( "value", ({ 490, "silver" }) );
}