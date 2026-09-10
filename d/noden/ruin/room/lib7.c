// lib7.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大圖書館．秘室");
    set_long(@C_LONG
這是一間陰暗的小房間，裡面的擺設雖然簡單，但是卻不失一種高雅的韻
致，充份顯露出主人的良好教養及品味。房間的天花板是個閃爍著光芒的魔法
力場，牆角的桌上有著一本書 (book) 不知道寫些什麼。
C_LONG
    );
    set("exits", (["up" : AREA"lib6"]));
    set("item_desc", (["book" : "好像是某人的日記，或許你可以閱讀它。\n"]));
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_read", "read");
}

int to_read(string s)
{
    int page;

    if (!s)
	return notify_fail("你想讀什麼?\n");

    if (s == "book" || s == "diary")
    {
	cat(DIARY"diary1");
	return 1;
    }
    else if (sscanf(s, "page %d", page) == 1)
    {
	if (file_exists(DIARY"diary" + page))
	{
	    cat(DIARY"diary" + page);
	    return 1;
	}
	else
	    return notify_fail("日記上沒有這一頁。\n");
    }
}

