#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Red scarf", "紅色圍巾");
        add( "id", ({ "scarf"}) );
        set_short("Red scarf", "紅色圍巾");
        set_long(@AAA
這是一條紅色的圍巾，是忍者加爾福特愛用的圍巾，據說
是娜考璐璐親手織給他的
AAA
        );
        set( "unit", "條"); 
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 4 );
        set("material","cloth");
        set("special_defense",([ "fire" : 20 ]));
        set( "weight", 20 );
        set( "value",({ 660, "silver" }) );
}
