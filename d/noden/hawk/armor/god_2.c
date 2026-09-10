#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Zeus Amulet","宙斯淡玉護身符" );
        add( "id", ({ "amulet","zeus amulet" }) );
        set_short( "宙斯淡玉護身符" );
        set_long(
                "希臘諸神之首宙斯的護身符，晶瑩淡雅的翠玉反而更顯出護身"+
                "符的氣派\n"
        );
        set( "unit", "個" );
        set("material","scholar");
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set( "value", ({ 2510, "silver" }) );
}
