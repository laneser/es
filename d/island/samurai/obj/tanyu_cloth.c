#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu cloth", "天羽戰衣");
        add( "id", ({ "cloth","clothes" }) );
        set_short("tanyu cap", "天羽戰衣");
        set_long(@AAA
這是天羽劍派特有的戰鬥裝，有不錯的防護力
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 25 );
        set( "defense_bonus", 4 );
        set("material","light_metal");
        set( "weight", 130 );
        set( "value", ({ 700, "silver" }) );
}
