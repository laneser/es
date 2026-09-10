#include "../takeda.h"
inherit ARMOR;

void create()
{
        set_name("Blue amulet", "藍蠍紋徽");
        add( "id", ({ "amulet" }) );
        set_short("blue amulet", "藍蠍紋徽");
        set_long(
                " .\n",
                "這是一個造形精巧的護身符，其上有一個藍色大蠍子\n"
                "的圖案，鮮□的色彩似乎隱藏神秘的力量在其中．\n"
        );
        set( "unit", "個");
        set( "type", "misc" );
        set( "material", "elemental");
        set( "armor_class", 0);
        set( "defense_bonus", 6 );
        set( "special_defense",
             ([ "evil":-4, "divine":-8,"poison":10 ]) );
        set( "weight", 20 );
        set( "value", ({ 1500, "silver" }) );
}
