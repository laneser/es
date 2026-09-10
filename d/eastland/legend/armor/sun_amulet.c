#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name("sun amulet", "日符");
     add( "id", ({ "amulet" }) );
     set_short( "日符");
     set_long(@C_LONG
一個有著九顆太陽的護符。相傳這護符上的九日是被后羿射下的烏鳥的魂魄附著而
成的，於是你握在手中還會感覺到陣陣的溫暖傳來。
C_LONG
     );
     set("unit","個");
     set("material","cloth");
     set( "type", "misc" );
     set( "defense_bonus", 9 );
     set( "weight", 5 );
     set( "value", ({ 150, "gold" }) );
}