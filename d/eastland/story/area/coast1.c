#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("沙灘");
	set_long( @LONG
你現在來到了一處平坦的白沙灘，西邊是一望無際的大海，頭頂是炙熱的豔陽
和一抹無垠的青空。波浪慢條斯理地拍打著沙岸，濺起些許水花；海風徐徐輕拂著
你的臉頰，吹散了周遭炙窒的熱氣，四肢百駭彷佛感受到它的恩惠，掃盡了酷署的
日照；沙灘上各式貝類星羅棋佈或遊走著小螃蟹；海里頭穿梭著五彩斑斕的魚兒。
徜徉在這一片白沙灘裡，頓時感到煩惱盡失，使你不再想到任何殺伐爭執。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SAREA"coast3", 
           "north" : SAREA"coast1",
           "south" : SAREA"coast2",
        ]) );
	reset();
}
