#include "../saulin_temple.h"
inherit ARMOR;

void create()
{
        set_name("eagle helmet", "飛鷹之盔");
        add( "id", ({ "helmet" }) );
        set_short("飛鷹之盔");
        set_long(@C_LONG
這是一頂由雪鷹皮做成的頭盔，相傳具有良好的防熱能力。 
它是一頂純白的皮盔，上面鑲著一隻小小的銀鷹。 
C_LONG
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "leather");
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "fire":8, "cold":-3, "electric":-5 ]) );
        set( "weight", 100 );
        set( "value", ({ 240, "gold" }) );
}