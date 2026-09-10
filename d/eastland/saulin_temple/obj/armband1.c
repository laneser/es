#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("armband of gun-in", "觀音臂環");
        add( "id", ({"armband", }) );
        set_short("觀音臂環");
        set_long(@C_LONG
臂環一般是頭陀使用的防具, 現在一些僧侶也使用臂環以增加防禦能力了。
觀音臂環相傳是觀音大士賜給座下天將的信物, 是一種榮譽和神聖的象徵。
C_LONG
        );
        set( "unit", "個");
        set( "type", "arms" );
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "material","leather" );
        set( "weight", 38 );
        set( "value", ({ 950, "silver" }) );
}
