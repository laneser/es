#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Sakura Clothes", "櫻之服");
        add( "id", ({ "clothes"}) );
        set_short("Sakura Clothes", "櫻之服");
        set_long(@AAA
這是一件繡有櫻花圖案的長袍
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 31 );
        set( "defense_bonus", 2 );
        set("material","cloth");
        set( "weight", 110 );
        set( "value", ({ 1160, "silver" }) );
}
