#include "../echobomber.h"

inherit ROOM;

void create()
{
  ::create();
  set_short("the stranger place","一個奇怪的地方");
  set_long(@Long
Long
,@CLong
一個奇怪的地方,你的思考忽然頓了一下..........
一個奇怪的洞口出現在井壁邊,你可以繼續往上爬,\或是進去洞口看一看.
但是一股邪氣從洞口發出......
CLong
);
set( "c_item_desc",([
     "hole":"一個很奇怪的洞,似乎危險與死亡正在裡面等著你.\n"
     ]) );
  
set( "exits",([
             "down":Deathland"/dwarf/well01",
             ]));

}

void init()
{
   add_action("to_climb","climb");
   add_action("to_enter","enter");
}

int to_climb()
{
    this_player()->move_player(Deathland"/dwarf/village_07",({
      "%s繼續往上爬.\n",
      "%s 從井裡爬了出來.\n",
      }) ); 
    return 1;
}

int to_enter(string str)
{
   if (!str||str!="hole") return 0;
    
   this_player()->set_explore( "deathland#16" ); 
   this_player()->move_player(Deathland"/dwarf/village_0a",({
      "%s進入了那個邪惡的洞口.\n",
      "%s從外面進來.\n",
       }) );
    return 1;
    
} 
