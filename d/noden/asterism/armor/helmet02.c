#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name(" Steel helmet", "高級鋼盔");
        add( "id", ({ "helmet" }) );
        set_short( "高級鋼盔");
        set_long(
                "這是一頂檢驗合格的鋼製頭盔 \n"
        );
        set("unit","頂");
        set( "type", "head" );
        set("material","heavy_metal");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 75 );
        set( "value", ({ 165, "gold" }) );
}



