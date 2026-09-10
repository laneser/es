#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("chainmail", "鎧甲");
        add( "id", ({ "mail","chainmail" }) );
        set_short( "鎧甲" );
        set_long(
                "用特殊的金屬所製成的鎧甲。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set( "material", "light_metal" );
        set( "armor_class", 13 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "mental":3, "evil":-2 ]) );
                       
        set( "weight", 150 );
        set( "value", ({ 300, "silver" }) );
}






