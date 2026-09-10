#include <mudlib.h>
inherit ARMOR;
 
void create()
{
        set_name("red pants","紅短褲");
        add("id",({"pants"}) );
        set_short("紅短褲");
        set_long(
"這是一件紅色的短褲，通常在軍中只有士官和憲兵才能穿。\n"
        );
        set( "unit", "件" );
        set( "weight", 30 );
        set( "type", "legs" );
        set( "material", "cloth" );
        set( "armor_class", 3 );
        set( "defense_bonus", 0 );
        set( "value", ({ 50, "silver" }) );
}
