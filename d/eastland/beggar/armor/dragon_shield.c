#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "dragon shield", "絕龍牌" );
        add( "id", ({ "shield" }) );
        set_short( "絕龍牌" );
        set_long(@C_LONG
一面有刀劍斫擊留下痕跡的盾牌,想必是替主人擋下了不知多少次的攻擊。在盾牌
上還有一隻張牙舞爪的青龍,甚是兇猛貌,對於敵人或許有些許的恫赫作用。  
C_LONG       
        );
        set("unit","塊");
        set( "type", "shield" );
        set( "material", "cloth" );
        set( "armor_class",7 );
        set( "defense_bonus", 1 );
        set( "weight", 100 );
        set( "value", ({ 1360, "silver" }) );
}
