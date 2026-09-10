#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("elven boots", "精靈鞋");
        add( "id", ({ "boots" }) );
        set_short( "精靈鞋" );
        set_long(
                "這是精靈王用獨角獸皮加上精靈族特殊的秘方所烘製成的鞋子 \n"
                "，穿起來既舒適又耐用，相信會給你的腳帶來極大的保護。\n"
        );
        set( "unit", "雙");
        set( "type", "feet" );
        set( "material", "leather");
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "mental":5, "evil":-3, "fire":-1 ]) );
                       
        set( "weight", 50 );
        set( "value", ({ 800, "silver" }) );
}
