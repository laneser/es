// eda7.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("秘室");
    set_long(@C_LONG
你被傳送到一間秘室裡，這秘室到處充滿著一種肅殺的氣氛，令人
感到很不自在。北方的牆壁上有個神龕 (niche)，裡頭飄浮著一個發光
的黃色水晶，水晶的上頭似乎有些奇怪的圖案。
C_LONG
    );
    set("light", 1);
    set("item_desc", ([
	"niche" : @NICHE
這是一個由大理石所雕制而成的神龕，神龕的前方有個小牌子，上面寫
著：「迷途的羔羊啊! 對波西鳳之印虔誠地祈禱吧! 」。
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

    if (p->query(QUESTNAME) > 3)
    {
        return notify_fail("你已經畫過一次了，就省省力氣吧。\n");
    }

    p->set(QUESTNAME, 3);
    tell_object(p, "你小心翼翼地把波西鳳之印描繪在魔法字典的筆記欄裡。\n");
    return 1;
}

int to_pray()
{
    object p;
    p = this_player();
    tell_object(p, "你跪下來向水晶祈禱，祈禱些什麼好呢? ...\n");
    p->move(AREA"rose4");
    return 1;
}
