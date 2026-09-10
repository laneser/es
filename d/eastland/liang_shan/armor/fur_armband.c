#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("fur armband", "鞣牛皮臂環");
        add( "id", ({ "armband" }) );
        set_short( "fur armband", "鞣牛皮臂環");
        set_long(
                "A fur armband .\n",
                "一個用牛皮鞣製的臂環． \n"
        );
        set("unit","個");
        set( "type", "arms" );
        set( "material", "adventurer");
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "cold":-10]) );
        set( "weight", 40 );
        set( "value", ({ 66, "gold" }) );
        set( "extra_stats",(["str":-1,"con":-1]));
        set( "extra_skills",(["bandage":15,"whip":20]));
}



