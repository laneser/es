#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 0) ;
        set_short( "井裡" );
        set_long(
@LONG
這是井裡的一個小洞穴，綠色的井壁生滿青苔，你很難想像在這
麼狹小的空間裡竟然有人會在這裡生活，但是地上明明擺著一些食物
的殘渣和灰燼。
LONG
        );
        
        set( "exits", ([
		"out"  : Goomay"ruin3",
        ]) );
        set( "objects", ([
                "prisoner" : Mob"prisoner",
		]));
        reset();
}
