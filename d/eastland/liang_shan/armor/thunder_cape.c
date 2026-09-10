#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("thunder cape", "五雷天心護袍");
        add( "id", ({ "cloak","cape" }) );
        set_short("thunder cape","五雷天心護袍");
        set_long(
                "This is a cape that can avoid thunder...\n",
                "這是一件紅色的道袍，上面寫著一些護身的符□，據說公孫勝\n"
                "呼風喚雨時必定會穿上這件羅真人送的法袍，以避免閃電誤傷自己．\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "mage" );
        set( "armor_class", 7 );
        set( "defense_bonus", 10 );
        set( "special_defense",(["electric":20 ]) );
        set( "weight", 70 );
        set( "value", ({ 1275, "silver" }) );
}