// altar.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("波塔祭壇廣場");
    set_long(@C_LONG
你來到了一個安靜的令人發毛的地方，地上到處畫著神秘的符號，彷佛是
某種魔法的咒文。廣場的中央有一個祭壇 (altar)，你發現祭壇上有一尊飄浮
在空中的神像 (statue) 散發著溫暖的光芒，你不禁想走近看看。
C_LONG
    );
    set("exits", (["east" : AREA"rose4"]) );
    set("light", 1);
    set("item_desc", ([
	"altar" : @ALTAR 
一個散發著七彩光芒的祭壇，不知是用什麼做成的? 祭壇上刻著幾行小字
寫道：「至高無上的武神莉莉雅女王聖像，迷途羔羊誠心禱祝可得指引，願女
王榮光常伴吾儕左右。」
ALTAR
,
	"statue" : @STATUE
這是一尊雕刻的栩栩如生的女神像，雖然她的容貌並不十分美麗，但是眉
宇之間隱隱透著一股威嚴。
STATUE
       ]) );
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_pray", "pray");
    add_action("to_touch", "touch");
}

int to_search(string s)
{
    object p;
    p = this_player();

    if (s == "altar")
    	if (p->query(QUESTNAME) >= 1)
    	{
	    tell_object(p, "祭壇上有個小六芒星 (hexagram mark)，你不禁想摸摸它 (touch)。\n");
	    return 1;
        }
    return notify_fail("你想找什麼?\n");
}

int to_touch(string s)
{
    object p;
    p = this_player();

    if (s == "mark" || s == "hexagram" || s == "hexagram mark")
	if (p->query(QUESTNAME) >= 1)
	{
	    tell_object(p, "六芒星上傳來一陣波動衝擊著你的意識，當你回過神時發現自己被傳送到一個新的地方!\n");
	    p->move_player(AREA"min0", "SNEAK", "");
	    return 1;
        }

    return notify_fail("你想摸什麼?\n");
}

int to_pray()
{
    object p;
    p = this_player();
    tell_object(p, "你跪下來向神像祈禱，祈禱些什麼好呢? ...\n");
    p->move("/d/noden/nodania/sealroom");
    return 1;
}

