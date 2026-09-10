#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name( "elven leggings", "精靈脛甲");
        add( "id", ({ "leggings" }) );
        set_short( "精靈脛甲" );
        set_long(
                "這是精靈王用獨角獸皮加上精靈族特殊的秘方所烘製成的脛甲 \n"
                "，穿起來既舒適又耐用，相信會給你的腿帶來極大的保護。\n"
        );
        set( "unit", "件");
        set( "type", "legs" );
        set( "material", "leather" );
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "mental":8, "evil":-5, "fire":-2 ]) );
        set( "weight", 40 );
        set( "value", ({ 100, "gold" }) );
}
