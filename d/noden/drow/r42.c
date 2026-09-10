
#include "iigima.h"

inherit "/d/noden/drow/in_water";
void create()
{
        ::create();
           set_short("陰暗水池");
        set_long(
@LONG
這裡灰暗潮溼，積水約半公尺深，你聞到一股惱人的黴味，與
水流悉娑的聲音，你看到石牆上仍有蛇蛻下的皮黏掛在那兒，可見得
這裡還是有生物的。你往身旁一看，看到一副浸泡在水裡多年的骷髏
，旁邊還放了小偷最愛用的萬用小刀一把，看來是哪個倒楣的小偷以
前掛在這裡吧，四處找找，說不定可以找到他留下來的寶物唷。
LONG
        );
        set( "exits", ([
           "up":DROW"r29",
        ]) );
        set("objects", ([
             "mad snake": DRO"s7",
        ]) );
        set("pre_exit_func",(["west":"check_snake"]));
        reset();
}
int check_snake()
{
     if(present("mad snake",this_object())){
       write("猛暴海蛇迅速竄動，令你難以行動！\n");
       return 1;}
       return 0;
}
