
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("The Factory of Drawf mine","煉礦廠");
    set_long(@Long
Long
,@CLong
一堆一堆的礦石堆積在此,而一些有經驗的矮人礦工正在把礦石分類,然候送
上輸送帶.輸送帶的末端是一座巨大的火爐, 熊熊的火焰生生不息地燃燒著.這裡
是一座煉礦廠 .你看著這些非常進步的設備不禁懷疑以矮人的文明是如何造出這
些器具的 .有一些運礦車正在把礦石卸下,另一些空的運礦車正開出這裡去運礦.
每個矮人都非常辛勤的工作.而在地上有鐵軌鋪設著.專供運礦車通行使用.
CLong
);
set("open_cart",1);
set("exits",([
            "west":Deathland"/mine/mine_01",
             ]));

set("objects",([
    "homdlaser":Monster"/homdlaser",
   ]));
set("direction","west");
::reset();
}

int clean_up() { return 0; } 
