#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu cloak", "天羽披風");
        add( "id", ({ "cloak" }) );
        set_short("tanyu cloak", "天羽披風");
        set_long(@AAA
這是天羽劍派特有的披風，有不錯的防護力
AAA
        );
        set( "unit", "件"); 
        set( "type", "cloak" );
        set( "armor_class", 6 );
        set( "defense_bonus", 4 );
        set("material","light_metal");
        set( "weight", 50 );
        set( "value", ({ 660, "silver" }) );
}
