#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("broken symbol","破損的金牌");
        add( "id" , ({ "symbol" }) );
        set_short("破損的金牌");
        set_long(@LONG
這是一塊破舊的金牌，上面刻著彎彎曲曲的條紋，不知道是什麼東西，
看來能辨識它原來模樣的只有經驗豐富的當鋪或是古董店老闆了。
LONG
	);
        set("unit","塊");
        set("weight", 10);
        set("value", ({20, "silver"}) );
}
