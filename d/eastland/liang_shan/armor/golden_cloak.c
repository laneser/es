#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("golden cloak", "挽絨金繡絲羅袍");
        add( "id", ({ "cloak","cape" }) );
        set_short("golden cloak","挽絨金繡絲羅袍");
        set_long(
                "This is a golden beautiful cloak.\n",
                "一件用金絲和絨布做成的披風，非常燦爛奪目．\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "heavy_metal" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 100 );
        set( "value", ({ 1120, "silver" }) );
}