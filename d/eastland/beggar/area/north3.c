#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "north3", "村路" );
	set_long(@C_LONG
你現在正走在一條頗為寬大的村路上,約可容納兩匹馬並行。村路向南、北方
向延伸。這條村路整理得蠻乾淨的,路旁的植物修緝的很整齊,花兒欣欣向榮,比起
廣場那片光禿禿的景像自是不可而語。畢竟這條是連接幾個較大鋪子,可說是村內
最繁華的道路。雖是如此, 卻看不出任何人工刻意留下來的痕跡,這一定是出自於
某位名匠之手。東邊有一棟建築物,原來是『薪膽』客棧 ( wine shop )。
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
             "south":DBEGGAR"north2.c",
             "north":DBEGGAR"north5.c"
	]) );
        set("c_item_desc",([
             "wine shop":"一間三層高的房子,似乎可以進去看看 ( enter ) 。\n"
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
    if (str=="wine shop") {
       this_player()->move_player(DBEGGAR"wine_shop",({
           "%s進入了客棧裡。\n",
           "%s從外面走了進來.\n"}),"");
       return 1;
    }
    else {
       write("你想進入那裡?\n");
       return 1;
    }
}