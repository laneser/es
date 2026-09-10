#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("highsteel scales","青鋼鱗甲");
        add("id",({"scales"}) );
        set_short("青鋼鱗甲");
        set_long(
"這是一件鱗甲，上面是一片一片青色的鋼鐵鱗片。\n"
        );
        set( "unit", "件" );
        set( "weight", 200 );
        set( "type", "body" );
        set( "material", "heavy_metal" );
        set( "armor_class", 20 );
        set( "defense_bonus", 0 );
        set( "value", ({ 700, "silver" }) );
}
