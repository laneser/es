#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("beast cloak", "霞飛怪獸絳紅袍");
        add( "id", ({ "cloak","cape" }) );
        set_short("beast cloak","霞飛怪獸絳紅袍");
        set_long(
                "一件大紅的毛皮披風，上面有一個巨大的獸面圖案．\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "leather" );
        set( "armor_class", 7 );
        set( "defense_bonus", 4 );
        set( "special_defense",(["none":3,"magic":4,"fire":-2 ]) );
        set( "weight", 90 );
        set( "value", ({ 1300, "silver" }) );
}