#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("battle mirror", "護心鏡");
        add( "id", ({ "mirror" }) );
        set_short("battle mirror", "護心鏡");
        set_long(
                "a mirror for knights .\n",
                "掛在胸前防禦攻擊的小鏡子，算是護身符的一種...\n"
        );
        set( "unit", "塊");
        set( "type", "misc" );
        set( "material", "light_metal");
        set( "armor_class", 0);
        set( "defense_bonus", 3 );
        set( "special_defense",
             ([ "poison":5 ]) );
        set( "weight", 20 );
        set( "value", ({ 270, "silver" }) );
}
