#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("volcano-rocks platemail", "火山岩鎧甲");
        add( "id", ({ "platemail" }) );
        set_short( "火山岩鎧甲");
        set_long(
                "這件鎧甲乃是用火山岩製成。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set( "material", "stone");
        set( "armor_class", 23 );
        set( "defense_bonus",1);
        set( "special_defense", ([ "fire":5 , "cold":-2 ]) );
        set( "weight", 310 );
        set( "value", ({ 140, "gold" }) );
}






