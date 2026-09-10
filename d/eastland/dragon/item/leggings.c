#include "../../layuter.h"
inherit ARMOR;

void create()
{
        set_name( "occult leggings", "神秘脛甲");
        add( "id", ({ "leggings" }) );
        set_short("神秘脛甲");
        set_long(
                "這是用一種神秘的質料所製成的脛甲\n"
        );
        set("unit","雙");
        set( "type", "legs" );
        set( "material", "element");
        set( "armor_class", 8 );
        set( "defense_bonus", 2);
        set( "weight", 50 );
        set( "value", ({ 400, "gold" }) );
}






