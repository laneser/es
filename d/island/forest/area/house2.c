#include "../tsunami.h"

inherit ROOM;
inherit DOORS;

void create()
{
    ::create();
    set_short("研究室");
    set_long(@LONG
一進到這間房子，只見到處都是實驗用的儀器，雖然多，但卻整理的有
條不紊；實驗桌的後方排列著許多奇怪的大管子，裡面有一些沒見過的生物
，看來這兒是魔族研究生物兵器的場所。除了儀器外，桌上似乎還放了一些
頗吸引人的儀器，長得有點像水壺，用途倒是頗耐人尋味哦！
LONG
             );
    set("light",1);
    set("item_desc",([
        "canteen" : @LONG
這些水壺被很整齊放在一個離實驗儀器有一段距離的地方，似乎是有
特別用途的，不知道可不可以跟主人要來看一看？
LONG
             ]) );
    set("exits",([
        "west":AREA"house1"]) );
    set("objects",([
        "flamen":TMOB"flamen"]) );
    create_door("west","east",([
         "keyword" :({"Oak door","door"}),
         "status"  :"closed",
         "name"    :"oak door",
         "c_name"  :"橡木門",
         "c_desc"  :"一道有著精緻雕刻的橡木門"
               ]) );   
          reset();
}

