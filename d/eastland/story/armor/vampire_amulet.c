#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("night-Ghost amulet","九魔陰陽符");
        add( "id", ({ "amulet"}) );
        set_short( "九魔陰陽符");
        set_long(@C_LONG
九魔陰陽符相傳經由七七四十九天，由九個厲鬼生啖三十六個男女童再引入地磁真
火練化那九個厲鬼而製成的，由於此法大幹天和，故製作之後那持有人便遭雷亟，
之後，這符就不知道下落，據說，最後輾轉流入「妖□　谷辰」之手。
C_LONG
        );
        set("unit","張");
        set( "type", "misc" );
        set("material","cloth");
        set( "defense_bonus", 6 );
        set( "weight",5 );
        set("special_dfense",
                     (["evil":20]) );
        set( "value", ({ 2500, "silver" }) );
}



