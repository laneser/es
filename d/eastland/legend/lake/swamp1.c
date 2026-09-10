#include "../legend.h"

inherit ROOM;
inherit LAKE"in_swamp.c";

void create()
{
        ::create();
        set_short("沼澤");
        set_long( 
@LONG
你正走在一個泥濘的沼澤中，爛泥的臭味和泥漿裡醜陋的植物令你忍不住一陣
作惡。這地帶一直罕有人煙，甚至連一般的飛禽走獸也難覓其足跡。你現在站的地
方還只是沼澤的邊界，趁你還沒吸入過多沼氣之前快離開吧。
LONG
    );
    set( "exit_suppress", ({
         "east","south","west" }) );
    set("exits",([
            "east":LAKE"swamp0",
            "south":LAKE"swamp2",
            "west":LAKE"swamp1"
       ]) );
    set("objects",([
          "mosquito#1":LMONSTER"mosquito",
          "mosquito#2":LMONSTER"mosquito"
         ]) ); 
    reset();
}

