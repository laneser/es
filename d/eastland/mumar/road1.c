#include "mumar.h"
inherit ROOM;
 
void create()
{
        ::create();
        set_short("城門通道");
        set_long( @C_LONG_DESCRIPTION
你走進了牧馬關南門的通道。兩邊的壁上列著兩排熊熊燃燒著的火炬，照得人影
在地上亂晃。自古以來，牧馬隘口一直是東方大陸南北交通的唯一孔道，也是東方大
國對抗北敵的重要據點；因此，這座拱形的城門被設計成可以同時進出三十輛馬車的
大道，以求交通之便。從這兒往北遙望，在一片廣大的教場的盡頭，是一座同樣規模
的城門，西面的牆上則有道石門。
C_LONG_DESCRIPTION
        );
 
        set( "light", 1 );
        set( "exits", ([
                "south" : MUMAR"gate",
                "north" : MUMAR"square02",
                "west" : MUMAR"ladder01"
             ]));
        set( "objects", ([
                "guard#1" : MOB"gate_guard",
                "guard#2" : MOB"gate_guard" ]) );
        reset();
}
