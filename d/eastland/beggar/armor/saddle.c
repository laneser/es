#include "../dony.h"

inherit ARMOR;
 
void create()
{
        set_name( "saddle", "破馬鞍" );
        add( "id", ({ "saddle" }) );
        set_short( "破馬鞍" );
        set_long(@C_LONG
一個破破爛爛的馬鞍, 你覺得很奇怪怎麼會有這種垃圾裝備存在呢 ?        
C_LONG
        );
        set( "type", "saddle" );
        set( "material", "leather" );
        set( "armor_class", 3 );
        set( "defense_bonus", 5 );
        set( "weight", 100 );
        set( "value", ({ 100, "silver" }) );
}
