#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("elven cloak", "精靈披風");
        add( "id", ({ "cloak" }) );
        set_short( "精靈披風" );
        set_long(
                "這是精靈王用獨角獸皮加上精靈族特殊的秘方所烘製成的披風 \n"
                "，穿起來既舒適又耐用，相信會給你的身體帶來極大的保護。\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "leather");
        set( "armor_class", 4 );
        set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "mental":5, "evil":-3, "fire":-2 ]) );
        set( "weight", 80 );
        set( "value", ({ 1200, "silver" }) );
}
