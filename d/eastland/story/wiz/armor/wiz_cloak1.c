#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("cloak of king", "王者披風");
        add( "id", ({ "cloak" }) );
        set_short( "王者披風");
        set_long(@C_LONG
這是一件象徵王者地位的披風，後面印有一個皇冠圖形。  
C_LONG
        );
        set("unit","件");
        set("type", "cloak" );
        set("material","heavy_metal") ;
        set("armor_class",7);
        set( "defense_bonus",3);
        set("weight", 100 );
        set("value", ({ 310, "gold" }) );
}



