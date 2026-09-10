#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("god armbands", "觀音臂環");
        add( "id", ({"armband","armbands" }) );
        set_short("a god armbands", "觀音臂環");
        set_long(
        "An armband used by great monk.\n",
		"臂環一般是頭陀使用的防具, 現在一些僧侶也使用臂環以增加防禦能力了。\n"
		"觀音臂環相傳是觀音大士賜給座下天將的信物, 是一種榮譽和神聖的象徵。\n"
        );
        set( "unit", "個");
        set( "type", "arms" );
        set( "armor_class", 5 );
        set( "defense_bonus", 5 );
        set( "material","leather" );
        set( "weight", 38 );
        set( "no_sale", 1);
        set( "value", ({ 950, "silver" }) );
}
