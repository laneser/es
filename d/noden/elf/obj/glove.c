#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("elven gloves", "精靈手套");
        add( "id", ({ "glove","gloves" }) );
        set_short( "精靈手套" );
        set_long(
                "這是精靈王用獨角獸皮加上精靈族特殊的秘方所烘製成的手套 \n"
                "，穿起來既舒適又耐用，相信會給你的手帶來極大的保護。\n"
        );
        set( "unit", "雙");
        set( "type", "hands" );
        set( "material", "leather" );
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "mental":6, "evil":-5, "fire":-2]) );
                       
        set( "weight", 40 );
        set( "value", ({ 800, "silver" }) );
        set( "no_sale", 1);
}
