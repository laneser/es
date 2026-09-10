#include <mudlib.h> 
inherit ARMOR;

void create()
{
        set_name("headband", "必勝頭帶");
        set_short("a headband", "必勝頭帶");
        set_long(
                "A cloth headband .\n",
    "這是一條用銀獸的皮甲編成的厚頭帶，一般都是將它綁在頭上用來祈求勝利。 \n"
    "它上面佈滿汗水和灰塵，還有黃色的細沙。 \n"
        );
        set("unit","條");
        set( "type", "head" );
        set( "material", "leather");
        set( "armor_class", 6 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "fire":1, "cold":1, "electric":-2 ]) );
        set( "weight", 45 );
        set( "value", ({ 100, "gold" }) );
}



