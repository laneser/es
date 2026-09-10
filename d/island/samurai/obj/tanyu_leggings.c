#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu leggings", "天羽護膝");
        add( "id", ({ "leggings" }) );
        set_short("tanyu leggings", "天羽護膝");
        set_long(@AAA
這是天羽劍派特有的護膝
AAA
        );
        set( "unit", "件"); 
        set( "type", "legs" );
        set( "armor_class", 7 );
        set( "defense_bonus", 3 );
        set("material","light_metal");
        set( "weight", 50 );
        set( "value", ({ 560, "silver" }) );
}
