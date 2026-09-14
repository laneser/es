#include "../takeda.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "狹窄通道" );
	set_long(@C_LONG
你進入了山洞中的狹窄通道，潮溼而且陰暗，空氣中瀰漫著一股說不出來
的噁心氣味，你仔細的分析它，有黴味，動物排洩物的氣味，甚至還有屍體腐
敗的味道。北邊一面巨大的巖璧擋住了這個通道，東方有一個積水的池子(pool)，
池子的下面好像有一些怪異，也許你該潛下去看看?
C_LONG	
	);
         set("c_item_desc",(["pool":
         "一個奇怪的小池子，裡面的東西好像不是水，而是一種黏稠的暗 \n"
         "紅色液體，該不會是血吧??\n"
         ,"wall":
         "這個牆看起來怪怪的，好像正在不停的輕輕晃動著...\n"
             ]));
        
        
        
        set( "exits", ([
                "north" : TROOM"lair/lair3",
                "south" : TROOM"lair/lair1"
        ]) );
        set( "exit_suppress", ({
                 "north" }) );
                 
        set("pre_exit_func",(["north":"check_wall"]));
        set( "objects", ([
                "sco1" : TMONSTER"scopio",
                "sco2" : TMONSTER"scopio"
        ]) );
        reset();
}
void init()
{
add_action("suicide","dive");
}
int check_wall()
{
   write("你試著往北邊走走看，嚇，原來這面牆是幻影啊....\n");
   return 0;
}   
int suicide()
{
    if ( this_player()->query_skill("swimming") < 30 ) {
    write("當你的腳碰到冰冷的水池，你突然開始懷疑你的游泳技術....\n");
    return 1;
    }
    if ( present("scorpion",this_object()) ) {
    write("別忙，先殺掉蠍子再過去吧....\n");
    return 1;
    }
    write("你跳進冰涼的池裡，奮力往下游去.......\n");
    this_player()->move_player(TROOM"lair/lair4","通.......一個人突然遊了進來\n");
    return 1;
}
int clean_up() { return 0; }
