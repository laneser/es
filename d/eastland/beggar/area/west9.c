#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "west9", "村路" );
	set_long(@C_LONG
你現在正走在一條由碎石子鋪成的村路上,村路延申到這裡似乎已是盡頭。村
路不很大,約可容納一匹馬行駛的寬度。在路旁長著一些奇形怪狀的植物 ,那上面
更開著許多不知名的小花,小花聞起來有點淡淡的香味, 那味道說不出的使得你心
曠神怡。鳥語蛙嗚, 頓時你煩惱盡失,站在這裡真是有如仙境。西邊是一大片的竹
林,而南邊的竹林再過去是一些矮矮的小山丘。你的東邊有一間小房子( house )。
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
                        "north":DBEGGAR"west7.c"	              
	]) );
        set("c_item_desc",([
               "house":"一間用磚頭做的房子,似乎可以進去看看 ( enter ) 。\n"
        ]) );
        ::reset();
}
void init()
{
     add_action("to_enter","enter");
}
int to_enter(string str)
{
     if (!str) return 0;
     if (str=="house") {
        this_player()->move_player(DBEGGAR"vice_master_room",({
              "%s進入了一間磚做的房子。\n",
              "%s從外面走了進來.\n"}),"");
        return 1;
     }
     else {
        write("你想進入那裡?\n");
        return 1;
     }
}      