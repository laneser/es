#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "fencing clothes", "劍術道服 ");
        add( "id", ({ "cloth","clothes" }) );
        set_short("fencing clothes", "劍術道服");
        set_long(@AAA
一個練劍道人所穿的道服，是用厚麻布所織成，擁有不錯的防護力
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 20 );
        set( "defense_bonus", 2 );
        set("material","cloth");
        set( "weight", 130 );
        set( "value", ({ 600, "silver
        " }) );
}
