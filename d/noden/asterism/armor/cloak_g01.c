#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("cloak of elder", "長老斗篷");
        add( "id", ({ "cloak" }) );
        set_short( "長老斗篷");
        set_long(
                "地精長老院做為識別的鬥蓬。\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set("material","cloth") ;
        set( "armor_class", 8 );
        set( "defense_bonus", 4 );
        set("special_defense",
              (["fire":8,"cold":8,"evil":15,"magic":10]) );
        set( "weight", 90 );
        set( "value", ({ 205, "gold" }) );
}



