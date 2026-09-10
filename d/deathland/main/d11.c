
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
 set_short("深淵南方");
set("long",@Long_description
從這往北看去,有一個非常大,又非常深的深淵橫在你的面前,似乎讓人覺得它就
是通往地獄的入口.這裡有三個帳篷(tents),而三個帳篷中有一堆營火(campfire)放
置著
Long_description
	);
set("exits",(["west":Deathland"/main/d9",
              ]));
set("item_desc",([
    "campfire":"一堆已被熄滅的營火.\n",
    "tents":"三個很大的帳蓬,其中一個帳蓬是敞開的,好像正歡迎著每個人進入那裡.\n"
               ]) );

}

void init()
{
 add_action("to_enter","enter");

}

int to_enter(string str)
{
    if (!str||str!="tent") return 0;
    this_player()->move_player(Deathland"/main/shop",({
    "%s進入了帳蓬.\n",
    "%s從外面走了進來.\n"}),"");
    write("你好像走進了一間商店.\n");
    return 1;
}
