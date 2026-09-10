#include "../oldcat.h"

inherit ARMOR;

void create()
{
        set_name("fish_lether hat", "魚皮帽");
        add( "id", ({ "hat" }) );
        set_short( "魚皮帽");
        set_long(
                "這頂魚皮帽能使人戴上後不怕風吹雨打。\n"
        );
        set("unit","件");
        set( "type", "head" );
        set( "material", "leather");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "electric":5 ]) );
        set( "weight", 50 );
        set( "value", ({ 230, "gold" }) );
        set( "no_sell",1);
}






