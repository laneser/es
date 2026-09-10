#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_boots ", "武士長靴 ");
        add( "id", ({ "boots" }) );
        set_short("samurai_boots", "武士長靴 ");
        set_long(@AAA
一個武士們制式穿的長靴
AAA
        );
        set( "unit", "件"); 
        set( "type", "feet" );
        set( "armor_class", 7 );
        set( "defense_bonus", 3 );
        set("material","leather");
        set( "weight", 100 );
        set( "value", ({ 600, "silver"
         }) );
}
