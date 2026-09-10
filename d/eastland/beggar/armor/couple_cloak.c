#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("cloak of couples", "黑披風");
        add( "id", ({ "cloak" }) );
        set_short( "黑披風");
        set_long(@C_LONG
黑披風是由天山二老採集十頭黑熊的皮所製成的。 由二老之一摜用毒的鶴老在上
面塗上一層薄薄防毒藥物。如果你怕被人下毒, 那你可以穿這件披風喲!!
C_LONG
        );
        set("unit","件");
        set( "type", "cloak" );
        set("material","leather") ;
        set( "armor_class", 5 );
        set( "defense_bonus",2 );
        set("special_defense",
              (["poison":10]) );
        set( "weight", 90 );
        set( "value", ({ 100, "gold" }) );
}



