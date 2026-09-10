// min7.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("神殿內廳");
    set_long(@C_LONG
你現在在神殿的內廳裡，凜冽的寒風依然吹個不停，你不由得緊了
緊身上的衣服。北方的牆壁上有個神龕 (niche)，裡頭飄浮著一個發光
的橙色水晶，水晶的上頭似乎有些奇怪的圖案。
C_LONG
    );
    set("exits", ([
	"south" : AREA"min6"
	]) );
    set("light", 1);
    set("item_desc", ([
	"niche" : @NICHE
這是一個由大理石所雕制而成的神龕，神龕的前方有個小牌子，上面寫
著：「迷途的羔羊啊! 對巴拉斯之印虔誠地祈禱吧! 」。
NICHE
	]) );
    reset();
}

void init()
{
    add_action("to_sketch", "sketch");
    add_action("to_pray", "pray");
}

int to_sketch()
{
    object p;
    p = this_player();

    if (p->query(QUESTNAME) > 2)
    {
        return notify_fail("你已經畫過一次了，就省省力氣吧。\n");
    }

    p->set(QUESTNAME, 2);
    tell_object(p, "你小心翼翼地把巴拉斯之印描繪在魔法字典的筆記欄裡。\n");
    return 1;
}

int to_pray()
{
    object p;
    p = this_player();
    tell_object(p, "你跪下來向水晶祈禱，祈禱些什麼好呢? ...\n");
    p->delete_temp("lilia_pass");
    p->move(AREA"rose4");
    return 1;
}
