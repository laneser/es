#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding scarf", "絲質領巾");
        add( "id", ({ "scarf" }) );
        set_short("a scarf for Gentlemen", "絲質領巾");
        set_long(
                "A beautiful scarf for gentlemen on meeting.\n",
                "一條男士在正式場合結的領巾。\n"
        );
        set("unit","條");
        set( "type", "cloak" );
        set( "material","cloth" ) ;
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 55 );
        set( "no_sale", 1 );
        set( "value", ({ 1800, "silver" }) );
}
