#include "../saulin_temple.h"
inherit ARMOR;

void create()
{
        set_name("stone helmet", "大地之盔");
        add( "id", ({ "helmet" }) );
        set_short("大地之盔");
        set_long(@C_LONG
這是一頂由石頭做成的頭盔，相傳是野蠻人中偉大的戰士才能使用的護具。 
它吸收了大地的精華，所以很重但也有極佳的防護力。 
C_LONG
                   );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "stone");
        set( "armor_class", 8 );
        set( "defense_bonus", 1 );
        set( "special_defense",
               ([ "fire":3, "cold":-3, "electric":2 ]) );
        set( "weight", 120 );
        set( "value", ({ 80, "gold" }) );
}