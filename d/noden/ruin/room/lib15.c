// lib15.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大圖書館．展覽室");
    set_long(@C_LONG
這房間裡空空湯湯，只有一張大石臺，上頭安置著一個閃閃發亮的水晶球。
石臺的前方有個小牌子，上面寫著：「傳說中的神奇水晶球，可以指引勇者到試
煉的地方去。」
C_LONG
    );
    set("exits", (["down" : AREA"lib11"]));
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_touch", "touch");
}

int to_touch(string str)
{
    object p;
    p = this_player();

    if (str == "ball" || str == "crystal ball" || str == "水晶球")
    {
	if (p->query(QUESTNAME) >= 6)
	{
            tell_object(p, "水晶球呼應你身上封印的力量，發出一道光芒籠罩著你，你發現自己被傳送到別的地方!\n");
            p->move_player(AREA"tower0", ({"%s被一道詭異的光芒傳送走了!\n", "%s伴隨著一道光芒出現在這裡。\n"}), "" );
        }
	else
	    tell_object(p, "你摸了摸水晶球，但是似乎什麼事情都沒有發生。\n");

	return 1;
    }
    else
        return notify_fail("你想摸什麼? 隨便亂摸是不好的行為哦 ....\n");
}

