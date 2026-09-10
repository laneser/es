#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "north11", "村路" );
	set_long(@C_LONG
你現在正走在一條由碎石子鋪成的村路上,村路延申到這裡似乎已到盡頭。村
路不很大,約可容納一匹馬行駛的寬度。在路旁長著一些奇形怪狀的植物 ,那上面
更開著許多不知名的小花,小花聞起來有點淡淡的香味, 那味道說不出的使得你心
曠神怡。鳥語蛙嗚, 頓時你煩惱盡失,站在這裡真是有如仙境。你西邊是一大片竹
林,而東邊有一棟白色的建築物 ( building ) 原來是『賞善罰惡廳』。
C_LONG
	);
        set_outside("noden");
        set( "exit_suppress", ({
                        "west" }) );
	set( "exits", ([
               "north":DBEGGAR"north10.c",
	        "west":DBEGGAR"forest1.c"
	]) );
        set("c_item_desc",([
               "building":"一棟白色的建築物,建築物的前面有兩隻石獅子。\n"
        ]) );
     reset();
}

void init()
{
   add_action("to_enter","enter");
}

int to_enter(string str)
{
    if (!str) return 0;
    if (str=="building") {
        this_player()->move_player(DBEGGAR"master_room",({
            "%s進入了一間矮矮的房子。\n",
            "%s從外面走了進來.\n"}),"");
        return 1;
    }
    else {
        write("你想進入那裡呢?\n");
        return 1;
    }
}    