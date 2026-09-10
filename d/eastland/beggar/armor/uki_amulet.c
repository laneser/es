#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("doctor amulet", "醫者護符");
        add( "id", ({ "amulet" }) );
        set_short( "醫者護符");
        set_long(@C_LONG
這是一個很普通的護符,上面繡有一堆簡要的行醫用術語, 與其說是一本字典還比
較恰當。
C_LONG               
               );
        set("unit","個");
        set("material","element");
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 6 );
        set( "weight", 5 );
        set( "value", ({ 110, "gold" }) );
}



