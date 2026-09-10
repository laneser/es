// g2.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("破敗的小廟");
    set_long(@C_LONG
荒蕪的草叢裡，有一間破敗的小廟，裡頭似乎有個神龕 (niche)。
一片荒煙蔓草中，似乎有著條小路通往北方和西方。來到這裡，你覺得
四周的空氣似乎凝結著，彷佛是某種不祥的預兆。
C_LONG
    );
    set("light", 1);
    set("item_desc", ([
	"niche" : @NICHE
這是一個由大理石所雕制而成的神龕，神龕的前方有個小牌子，上面寫
著：「迷途的羔羊啊! 對萬能的東方故事諸神虔誠地祈禱吧! 」。
NICHE
	]) );
    set("exits", ([
	"north" : AREA"g3",
	"west" : AREA"g1"
	]) );
    set("objects", (["ghost" : MOB"ghost"]));
    reset();
}

void init()
{
    add_action("to_pray", "pray");
}

int to_pray()
{
    object p;
    p = this_player();
    tell_object(p, "你跪下來祈禱，祈禱些什麼好呢? ...\n");
    p->move(AREA"rose4");
    return 1;
}
