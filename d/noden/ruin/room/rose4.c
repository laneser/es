// rose4.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("城市大道");
    set_long(@C_LONG
這裡是羅斯托麗城的城市大道，在你的南方是緊閉的城門。東邊聳立著一
棟高大的建築物 (building) ，還有一座圓形的廣場 (square) 隔著道路與這
棟建築物相望。令你納悶的是，這裡居然還有保持的如此完整的建築，真是不
可思議。
C_LONG
    );
    set("exits", (["north" : AREA"rose5"]) );
    set("item_desc", ([
	"building" : @BUILDING
這棟美輪美奐的建築充份顯示出古魔族帝國的強大，華麗的雕刻、高聳的
門柱，透露著古代文明的高度發達。半開的正門前有著一塊石碑，上面題著：
「吾神女王的恩賜，先人傳承的累積  羅斯托麗大圖書館」。
BUILDING
,
	"square" : @SQUARE
廣場的入口立著一個小石碑，上頭寫著：「波塔祭壇，閒雜人等進入者處
死......大祭司米達爾奉旨公告周知」。
SQUARE
	]) );
    reset();
}

void init()
{
    add_action("to_enter", "enter");
}

int to_enter(string str)
{
    if (str == "building" || str == "library")
	this_player()->move_player(AREA"lib0", "SNEAK", "");
    else if (str == "square" || str == "altar")
	this_player()->move_player(AREA"altar", "SNEAK", "");
    else
	return notify_fail("你想進入哪裡?\n");

    return 1;
}
	

