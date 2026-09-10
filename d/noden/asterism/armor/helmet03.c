#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("turban", "纏頭巾");
        add( "id", ({ "turban" }) );
        set_short( "纏頭巾");
        set_long(
                "地精愛用的纏頭布。\n"
        );
        set("unit","條");
        set( "type", "head" );
        set("material","cloth") ;
// set( "armor_class", 3 );
   set( "armor_class", 5 );
// set( "defense_bonus", 7 );
   set( "defense_bonus", 5 );
// fixed by mad
        set( "weight", 30 );
        set( "value", ({ 2, "gold" }) );
}



