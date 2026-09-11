#include "takeda.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "神火炮營" );
	set_long(
	"你來到山頂上的一片空曠平地，這裡就是梁山泊著名的神火炮營，由轟天雷\n"
	"凌振指揮。梁山泊之所以能夠履敗官兵，除了勇將與天險之外，神火炮營也是其\n"
	"中一個重要的因素。這些火炮(cannon)現在正羅列在崖邊，射程涵蓋了從大石橋\n"
	"到幽國城的廣大土地。\n"  
	);
	set_outside("eastland");
        set("c_item_desc",(["cannon":
"這是用上好的青銅鑄成的巨型火炮，是利用默爾斯人所發現的神奇爆炸粉來發射\n"
"炮彈的，炮身中空，足足有兩個人那麼長，外面刻著許多奇怪的符號。\n"
            ]));        
        set( "exits", ([
                "down" : TROOM"yard1",
                "north" : TROOM"gate3" 
        ]) );
        set( "objects",([
                "ling":TMONSTER"lingchen",
                ]));
        reset();
}
int clean_up() { return 0; }