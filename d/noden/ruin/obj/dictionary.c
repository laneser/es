// Rune Dictionary

#include "../lilia.h"

inherit OBJECT;

void init()
{
    add_action("do_read", "read");
}

void create()
{
    set_name("Rune Dictionary", "魔法字典");
    add("id", ({"dictionary", "dic"}));
    set_short("魔法字典");
    set_long(@C_LONG
這是達特紐斯送給你的魔法字典，上頭寫著密密麻麻的魔族古文字和現代
文字的對照表，字典的最後面還有著幾頁空白的筆記欄 (note) ，讓你可以記
錄你沿路所看到的特殊事蹟。 
C_LONG
	);
    set("unit", "本");
    set("no_sale", 1);
    set("no_drop", 1);
}

int do_read(string str)
{

    object p;
    int lv;

    p = environment(this_object());

    if (str != "note")
        return notify_fail("讀什麼?\n");

    lv = p->query(QUESTNAME);
    if (lv)
        tell_object(p, "你的筆記欄上面畫著：\n\n");
    else
	return notify_fail("那上面一片空白，什麼也沒有。\n");

    if (lv >= 7)
        tell_object(p, "莉莉雅之印 (Seal o Lilia)\n");
    if (lv >= 6)    
	tell_object(p, "希特斯之印 (Seal o Hades)\n");
    if (lv >= 5)
        tell_object(p, "海地亞之印 (Seal o Hestia)\n");
    if (lv >= 4)
        tell_object(p, "弗雷斯之印 (Seal o Furies)\n");
    if (lv >= 3)
        tell_object(p, "波西鳳之印 (Seal o Persephone)\n");
    if (lv >= 2)
        tell_object(p, "巴拉斯之印 (Seal o Pallas)\n");
    if (lv >= 1)
        tell_object(p, "納突尼之印 (Seal o Naptune)\n");

    return 1;
}
 
