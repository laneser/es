#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("round shield","規圓盾");
        add("id",({"shield"}) );
        set_short("規圓盾");
        set_long(
"這是一面圓形的盾，上面是一圈一圈讓你看了發暈的圓。\n"
        );
        set( "unit", "面" );
        set( "weight", 150 );
        set( "type", "shield" );
        set( "material", "element" );
        set( "armor_class", 4 );
        set( "defense_bonus", 6 );
        set( "value", ({ 1500 , "silver" }) );
}
