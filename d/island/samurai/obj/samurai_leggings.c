#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_leggings", "武士護膝 ");
        add( "id", ({ "leggings" }) );
        set_short("samurai_leggings", "武士護膝");
        set_long(@AAA
一個武士們制式穿的護膝
AAA
        );
        set( "unit", "件"); 
        set( "type", "legs" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set("material","element");
        set( "weight", 100 );
        set( "value", ({ 600, "silver" }) );
}
