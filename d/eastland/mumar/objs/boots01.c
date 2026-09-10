#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("Octrophet Shoes","八卦玄鞋");
        add("id",({"shoes","boots"}) );
        set_short("八卦玄鞋");
        set_long(
"這是一雙鞋頭上安著一幅八卦的鞋子。\n"
        );
        set( "unit", "雙" );
        set( "weight",80 );
        set( "type", "feet" );
        set( "material", "cloth" );
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "value", ({ 2000, "silver" }) );
        set( "no_sale",1);
}
