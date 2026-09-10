// lib10.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大圖書館．書庫");
    set_long(@C_LONG
望著一個個堆滿書本的架子井然有序地排列在這個大房間裡，你知道你已經
來到了大圖書館的"心臟"書庫。處在這一片書海里，你深深地感受到一個偉大文
明的力量來源，也許有些書對你有用也說不定喲！
C_LONG
    );
    set("exits", ([
	"east" : AREA"lib11",
	"west" : AREA"lib9"
	]) );
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_read", "read");
}

int to_search()
{
    tell_object(this_player(), "在你面前的書架上有本紅皮書是翻開的 .... ? ....\n");
    return 1;
}

int to_read(string s)
{
    if (s == "red book" || s == "紅皮書")
	cat(DIARY"redbook");
    else
	tell_object(this_player(), "你想讀什麼?\n");

    return 1;
}



