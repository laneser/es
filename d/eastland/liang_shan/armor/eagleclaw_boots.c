#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("eagle boots", "鷹爪皮四縫乾黃靴");
        add( "id", ({ "boots" }) );
        set_short("eagle boots", "鷹爪皮四縫乾黃靴");
        set_long(
                "This is a pair of boots made of skin of eagle's claw .\n",
                "這是剝下老鷹腳爪上的皮曬乾製成的鞋子，聞起來有點怪味．\n"
        );
        set( "unit", "雙");
        set( "type", "feet" );
        set( "material", "leather");
        set( "armor_class", 4 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               (["energy":2 ]) );
        set( "weight", 60 );
        set( "value", ({ 640, "silver" }) );
}
