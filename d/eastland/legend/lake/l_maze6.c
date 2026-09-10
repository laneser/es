#include "/d/eastland/legend/legend.h"

inherit LAKE+"in_lake1";
int be_search,be_open;
void create()
{
        ::create();
    set_short("大海");
        set_long( 
@LONG
你劃著船槳來到了海面上，極目四眺，是一片風平浪靜的無垠大海，遠處幾艘
漁船正隨著波浪載浮載沈，撒網成群，辛勤地捕著漁。波面上不時穿梭著飛魚，陽
光反射其身上，好似一顆顆亮晶晶的銀寶石。美中不足的是，在小船旁漂來些許垃
圾。
LONG
    );
   set("c_item_desc",([
      "垃圾":"一堆漂浮在水面上的垃圾 ( garbage ) 。\n"
   ]) );
   be_search=0;
   be_open=0;
    ::reset();
}
void init()
{
  ::init();
  add_action("do_search","search");
  add_action("do_open","open");
}
int do_search(string arg)
{

   if ( be_search ) return 0;
   if ( !arg || arg!="garbage" ) return 0;
   if ( !this_player()->query_temp("captain_asked") ) return 0;
   
   be_search=1;
   tell_object(this_player(),"你從垃圾堆中找到一個小瓶子(bottle)。\n");
   set("c_item_desc",([
      "bottle":"   一個玻璃子，你可以試著打開(open)它。\n"
   ]) );
   return 1;
}
int do_open(string arg)
{
    object fruit;
    if (!arg || arg!="bottle") return 0;
    if (!be_search) return 0;
    if (be_open) return 0;
        be_open=1;
    tell_object(this_player(),
       "你打開小瓶子，忽見一個婀娜多姿的人形從瓶子裡面跑了出來．．\n");
    tell_object(this_player(),@C_LONG
「少女小漁」的魂魄說道：妾身乃是多年前死於大浪的漁村村長的未婚妻，因閭王
          感思念之深，特來與君相見。煩你覆村長說妾身永遠記得和他在一起的
          時光，若有來世，願與他再結連理。

「少女小漁」的魂魄有所感傷地消失了。   
C_LONG
    );
    this_player()->set_temp("wife_asked",1);
    delete("c_item_desc/bottle");
    call_out("back",300);
    return 1;
}
void back()
{
   be_search=0;
   be_open=0;
}
void reset()
{
    be_search=0;
    be_open=0;
    delete("c_item_desc/bottle");
    ::reset();
}
