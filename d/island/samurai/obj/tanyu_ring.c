#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu ring", "天羽指環");
        add( "id", ({ "ring" }) );
        set_short("tanyu ring", "天羽指環");
        set_long(@AAA
這是天羽劍派的掌們信物之一，天羽指環
AAA
        );
        set( "unit", "個"); 
        set( "type", "finger" );
        set( "armor_class", 0 );
        set( "defense_bonus", 6 );
        set("material","light_metal");
        set( "weight", 20 );
        set( "value", ({ 660, "silver" }) );
}
