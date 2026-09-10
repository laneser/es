#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "God-Dragon ring","□[1;37mP[0;37m□[1;37ms[0;37m□[1;37m□[0;37m" );
     
     add( "id",({ "ring" }) );
     set_short( "□[1;37mP[0;37m□[1;37ms[0;37m□[1;37m□[0;37m" );
     set_long(@C_LONG
一隻太白金精製成的戒指，戒指上雕刻著一條銀龍，栩栩如生，活脫活現。
C_LONG
     );
     set( "weight",5 );
     set( "unit", "只");
     set( "type", "finger" );
     set( "material","element" );
     set( "defense_bonus",10 );
     set( "value",({ 3000,"silver" }) );
}
