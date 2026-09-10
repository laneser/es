#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("gold helmet", "紅綴金束髮盔");
        add( "id", ({ "helmet" }) );
        set_short( "gold helmet", "紅綴金束髮盔");
        set_long(
                "A beautiful golden helmet .\n",
                "你看到一頂用金絲盤成的頭盔，邊緣有醒目的紅絲帶．美麗且不失其防護能力．\n"
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "light_metal");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "none":1, "magic":2]) );
        set( "weight", 80 );
        set( "value", ({ 260, "gold" }) );
}