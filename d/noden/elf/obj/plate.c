#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("chainmail of elf", "精靈鎧甲");
        add( "id", ({ "mail","chainmail" }) );
        set_short( "精靈鎧甲" );
        set_long(
                "這是精靈王用特殊的金屬加上大神揚小邪的祝福所製成的鎧甲，甲\n"
                "上有著精靈的的標幟。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set( "material", "light_metal");
        set( "armor_class", 30 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "mental":5, "evil":-3, "poison":-1 ]) );
        set("no_sale",1);
        set( "weight", 200 );
        set( "value", ({ 400, "gold" }) );
}
