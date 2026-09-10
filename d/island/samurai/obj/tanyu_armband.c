#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu armband", "天羽臂環");
        add( "id", ({ "armband" }) );
        set_short("tanyu armband", "天羽臂環");
        set_long(@AAA
這是天羽劍派特有的臂環，有不錯的防護力
AAA
        );
        set( "unit", "件"); 
        set( "type", "arms" );
        set( "armor_class", 3 );
        set( "defense_bonus", 1 );
        set("material","light_metal");
        set( "weight", 30 );
        set( "value", ({ 760, "silver" }) );
}
