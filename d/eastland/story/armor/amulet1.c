#include "../story.h"
inherit ARMOR;
inherit SARM"OR";

void create()
{
        set_name("buddha amulet","□符");
        add( "id", ({ "amulet" }) );
        set_short( "□符");
        set_long(@C_LONG
一個繡著□字符號的護符。除此之外，護符上滿是些佛字梵號，不時閃爍著光芒，
其光芒令你感到一陣陣的溫暖，相信是個很好的防具才對。
C_LONG
        );
        set("unit","個");
        set( "type", "misc" );
        set("material","cloth");
        set("the_one",1);
        set( "defense_bonus", 1 );
        set( "weight", 1 );
        set( "value", ({ 600, "gold" }) );
}



