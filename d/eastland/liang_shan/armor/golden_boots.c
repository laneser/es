#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("golden silk boots", "金線抹綠皂朝靴");
        add( "id", ({ "boots" }) );
        set_short("golden silk boots", "金線抹綠皂朝靴");
        set_long(
                "This is a pair of boots made of golden silk .\n",
                "這是用金線和絲綢作成的鞋子，美麗到你不忍心穿著它走路．\n"
        );
        set( "unit", "雙");
        set( "type", "feet" );
        set( "material", "leather");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 70 );
        set( "value", ({ 660, "silver" }) );
}
