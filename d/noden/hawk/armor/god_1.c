#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "Diamond Ring","維納斯白鑽" );
        add( "id", ({ "ring","diamond ring" }) );
	set_short( "維納斯白鑽" );
        set_long(
                "這是希臘月神維納斯的戒指，其上所鑲的白鑽是人間絕無僅有的。\n"
        );
        set( "unit", "只" );
	set("material","adv");
        set( "type", "finger" );
        set( "armor_class",0 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set( "value", ({ 7000, "silver" }) );
}
