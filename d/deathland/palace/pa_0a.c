
#include "../echobomber.h"

inherit ROOM;
void create()
{
	::create();
 set_short("","二皇子艾爾的起居室");
  set_long(@Long
Long
,@CLong
這裡是二皇子艾爾的起居室 . 一大堆奇奇怪怪的空瓶子擺在書桌(desk)上, 另外還
有十幾個書櫃(closet)放在這個房間中.你覺得這裡好像是一座圖書館而不像是一個皇子
的住處.
CLong
);

set("c_item_desc",([
    "desk":"上面擺滿了一堆空瓶子.你覺得那些瓶子應該是某些實驗所留下的.\n",
    "closet":"堆滿了一些用古文字所寫的書.\n",
    "book":"古文字寫的書\n"
    ]) );
    
set("exits",([
              "north":Deathland"/palace/pa_05",
             ]));
#include "../replace_room.h"
}
