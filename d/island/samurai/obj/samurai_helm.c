#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_helm ", "武士頭盔");
        add( "id", ({ "helm" }) );
        set_short("samurai_helm", "武士頭盔");
        set_long(@AAA
一個武士們制式穿的頭盔,用來保護頭部用
AAA
        );
        set( "unit", "件"); 
        set( "type", "head" );
        set( "armor_class", 7 );
        set( "defense_bonus", 1 );
        set("material","element");
        set( "weight", 70 );
        set( "value", ({ 780, "silver"
        }) );
}
