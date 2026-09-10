#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("silk gloves", "絲質手套");
        add( "id", ({"gloves" }) );
        set_short("絲質手套");
        set_long(
                "一雙絲質手套,可以讓武器的使用更加流暢\n"
        );
        set( "unit", "雙");
        set( "type", "hands" );
        set( "armor_class", 1 );
        set( "defense_bonus", 4 );
        set( "material","cloth" );
        set( "weight", 30 );
        set( "value", ({ 1250, "silver" }) );
}
