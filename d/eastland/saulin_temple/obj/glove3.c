#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
        set_name("black bracers", "黑□手釧");
        add( "id", ({"bracers","bracer" }) );
        set_short("黑□手釧");
        set_long(
"一雙由黑□巖的石頭製作成的手環, 可以幫助你在戰鬥中奪得勝利。\n"
        );
        set( "unit", "雙");
        set( "type", "hands" );
        set("material","stone");
        set( "armor_class", 3 );
        set( "defense_bonus", 4 );
        set( "weight", 60 );
        set( "value", ({ 1500, "silver" }) );
}
