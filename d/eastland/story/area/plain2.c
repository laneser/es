#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("草原");
	set_long(@LONG
你來到了一處空曠的草原，西和北邊是草原的延伸，南邊是大樹群，東南方似
乎有些許不太明顯的足跡。在草原上長滿了些小小的矮花，其顏色鮮□，香味撲鼻
，一群野蜂正悠哉地穿梭其間，恣意採著蜂蜜。你東邊是一面千仞高的山壁，上面
突出來大大小小的巖塊如疊格子般一層層的井然有序，與其說這山壁是經由石頭堆
積起來的！巖塊間有許多裂縫，你試了試發現其大小正足可以容納一隻腳的體積。
LONG
	);
	set("light",1);
	set( "exit_suppress", ({
	   "southwest"}) );
	set("exits", ([ 
                "west" : SAREA"plain1",
               "north" : SAREA"plain4",
           "southwest" : SAREA"village1",
        ]) );
        set("objects" , ([
           "boy#1" : SMOB"boy1",
           "boy#2" : SMOB"boy1",
          "girl#1" : SMOB"girl1",
          "girl#2" : SMOB"girl1",
        ]) );
	reset();
}
void init()
{
   add_action("do_search","search");
}
int do_search(string arg)
{
    write("你發現在在西南邊(southwest)的大樹群裡有條走過的痕跡！\n");
    return 1;   
}