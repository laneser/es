// lib9.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大圖書館．閱覽室");
    set_long(@C_LONG
這裡是大圖書館的閱覽室，石制的桌椅迄今仍完整地安置著，一如它們往日
所在的位置。這靜謐的閱覽室，不知已沈睡了多少日子了，但是室內的一切卻仍
然非常潔淨，可見魔族古帝國建築技術的高超。
C_LONG
    );
    set("exits", ([
	"east" : AREA"lib10",
 	"down" : AREA"lib0"
	]) );
    set("light", 1);
    reset();
}
    
