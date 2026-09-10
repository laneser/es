#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("rainbow ring","七彩琉璃戒");
        add( "id", ({ "ring" }) );
        set_short( "七彩琉璃戒");
        set_long(@C_LONG
一隻晶瑩剔透不時在陽光的照射下閃爍著七彩光芒的戒指。七彩琉璃戒是「羽民族
大首領  羽後」年輕時四處爭戰所配帶的戒指，防護力超強，是隻連天神都為之贊
嘆的稀世防具。
C_LONG
        );
        set( "unit","只");
        set( "type", "finger" );
        set( "material","element");
        set( "defense_bonus", 6 );
        set( "weight", 10 );
        set( "value", ({ 7500, "silver" }) );
}



