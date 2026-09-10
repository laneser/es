#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_cloak", "武士披風");
        add( "id", ({ "cloak" }) );
        set_short("samurai_cloak", "武士披風");
        set_long(@AAA
一個武士們制式穿的披風
AAA
        );
        set( "unit", "件"); 
        set( "type", "cloak" );
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set("material","leather");
        set( "weight", 70 );
        set( "value", ({ 800, "silver"
         }) );
}
