#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("lion helmet", "熟鋼獅子盔");
        add( "id", ({ "helmet" }) );
        set_short( "lion helmet", "熟鋼獅子盔");
        set_long(
                "A lion face helmet .\n",
                "這是一頂採獅子之形制作的盔甲，腦後還有許多黃色的鬃毛 \n"
                "看來十分雄壯威武．\n"
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "heavy_metal");
        set( "armor_class", 9 );
        set( "defense_bonus", 3 );
        set( "weight", 80 );
        set( "value", ({ 288, "gold" }) );
}



