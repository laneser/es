#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("fighter's ring","阿修羅之戒");
        add( "id", ({ "ring" }) );
        set_short( "阿修羅之戒");
        set_long(@C_LONG
這是阿修羅四處爭戰多時所配戴的戒指。傳說這戒指上面有股強大的魔力附著和一
道阿修羅的梵語祝福,如果是極其邪惡的人戴上它,會有很好的防護。
C_LONG
        );
        set("unit","只");
        set( "type", "finger" );
        set("material","cloth");
        set( "armor_class", 0 );
        set( "defense_bonus", 5 );
        set( "weight", 10 );
        set( "value", ({ 300, "gold" }) );
        set("special_defense",
                     (["evil":5]) );
                     
}



