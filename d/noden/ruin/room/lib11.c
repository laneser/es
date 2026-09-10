// lib11.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大圖書館．世界廳");
    set_long(@C_LONG
這是一個掛著「世界廳」牌匾的有趣房間，因為房間的地板上畫了一張圖，
上面有著註解：「帝國總覽圖」。「大概是因為這張地圖才稱做世界廳吧！」你
不由得打從心裡這樣想著。
C_LONG
    );
    set("exits", ([
	"east" : AREA"lib12",
	"west" : AREA"lib10",
	"north" : AREA"lib13",
	"south" : AREA"lib14",
	"up" : AREA"lib15"
	]) );
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search(string s)
{
    object p;
    p = this_player();

    if (s != "map")
	return notify_fail("你想找什麼? 這裡這麼大可能要找到明年喲 ...\n");

    if (p->query(QUESTNAME) >= 7)
    {
	tell_object(p, "當你凝神注視著這個地圖時，你感到一陣暈眩 ...\n");
	p->move(AREA"p0");
    }
    else
	tell_object(p, "這是一張很美麗的地圖，上面有山有水有鳥有魚 ...\n");

    return 1;
}
