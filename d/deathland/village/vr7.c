
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    //set("light",1);
    set_short("The beautiful building","優美的建築");
    set_long(@Long
Long
,@CLong
一棟優美的建築物,是由一個外來的妖精魔法師所成居住的地方.由外表看來,這裡裝
飾的富麗堂皇,美侖美奐,除此之外,最能吸引住你目光的焦點莫過於一個大書櫃(closet)
了,除此之外,有一個擺飾品與這個房間極不搭調,那就是一張好像小孩子畫的畫像(paint
ing),而且這畫像還特別的大,只要你人在這裡,你就不得不看著它.
CLong
    );
    set("c_item_desc",([
        "closet":"一個大書櫃,裡面的藏書驚人但是百分之九十九都是古文字,一\n"
                 "種失傳已久的古妖精文,已經沒有人認識了.\n",
        "painting":"畫著一隻妖精的畫像,但是拙劣的筆法令人發笑\n",
        "bottle":"@@to_look_bottle",
        ]) );
    set("search_desc",([
       "closet":"@@to_search_closet",
       "painting":"@@to_search_painting",
        ]) );
    set("exits",([
                "east":Deathland"/village/v14",
             ]));
    set("objects",([
        "impmage":Monster"/impmage",
        ]) );
    reset();
}

string to_look_bottle()
{
  this_player()->set_explore( "deathland#27" );
  return "一個很特殊的玻璃瓶,你很驚訝為何一個小小的玻璃瓶會有這麼大的魔力.\n";     
}

string to_search_closet()
{
      return "除了一大堆的書籍外還有一個小小的空瓶子.\n";
}

string to_search_painting()
{
    return "你期望能夠發現甚麼?一個隱藏在後的通道或是一個奇怪的按鈕.\n";
}

