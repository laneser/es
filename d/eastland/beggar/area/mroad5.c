#include "../dony.h"
inherit ROOM;

void create()
{
    ::create();
    set_short("田野");
    set_long( @C_LONG
你現在正走在一片青翠的田野上，四處綠草如茵，地上各色繁花。偶爾一陣清
風徐過，繁花如雨，五色繽紛，冉冉飛舞，似下不去；花隨同飛舞，漫天花香泌人
心脾，猶還染濡衣襟，久久不能散去；有時徐風如一股清流，自上而下，全身無不
通暢。田野東南邊是橫亙無綿的群峰，鄰近的是一面山壁，山壁下似乎有些足跡，
底部部份有個大洞 ( hole ) 。由此而北則是通往海威港。

C_LONG
);
                                
    set_outside( "haiwei" );
    set( "light", 1 );
    set( "exits", ([
           "north" : "/d/eastland/haiwei/mroad4" ]) );
    set( "objects",([
          "beetle1":DMONSTER"beetle",
          "beetle2":DMONSTER"beetle",
          "beetle3":DMONSTER"beetle",  
       ]) );
    set("c_item_desc",([
          "hole":@LONG
一個黑色的大洞，洞裡雜草叢生，有些空間似乎能讓你容身，
或許你可以擠進去(squeeze)。
LONG    
    ]) );
    reset();
}
void init()
{
   add_action("do_squeeze","squeeze");
}
int do_squeeze(string str)
{
   if ( !str || str!="hole" ) {
      write("你想要擠進那裡去呢？是要擠進洞裡 ( hole ) 嗎？\n");
      return 1;   
   }
   tell_object(this_player(),@LONG
   
你把身子擠進山洞裡，卻意外地發現經過剛才的大洞原來內中別有天地，
竟然有一個村落在這裡 ！ 
   
LONG 
   );  
   this_player()->move_player(DBEGGAR"cross",({
         "%s把身子擠進山壁底部的一個大洞裡。\n",
         "%s從外面走了進來.\n"}),"");
   return 1;
}