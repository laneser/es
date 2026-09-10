#include <mumar.h>
inherit ROOM;
 
int button = 1;
void create()
{
        ::create();
  set_short("牧馬關密道");
  set_long( @CLong
這兒是牧馬關地面之下的通道。幾乎所有軍事基地中，都會挖掘四通八達的地下
密道，以做為奇襲或撤退之用。看來這個密道挖掘的時間並不久，所以十分地狹窄而
潮□。東面的土牆上，刻著『牧馬關軍事重地，擅入者殺無赦』幾個大字，下面則掛
了一隻告示牌（sign) 。這裡靜得出奇，除了隧道頂上滴下的水滴聲外，只有你的呼
吸聲。
CLong
);
  set( "c_item_desc", ([
                "sign" : @LONG_TEXT
一隻綠底白字的告示牌，你似乎感覺曾在睡夢中看過類似的東西...上面寫著：
　┌——————————————┐
  │字　　號：(83)東字第Ｏ三八號│
　│工程名稱：牧馬關地下要塞工程│
　│施工單位：牧馬關．戰鬥工兵團│
  │負 責 人：大將軍．楊　上　昆│
  │工程說明：極　　　機　　　密│
  │                            │
  │施　工　中 ． 敬　請　期　待│
  └——————————————┘
LONG_TEXT
 ]) );
set("exits",([
               "up": MUMAR "square06" ]));
set( "search_desc", ([ "here" : "@@search_here" ]) );
        reset();
}
 
string search_here()
{
        object obj;
 
        if( !button || present("button", this_object()) ) return
                "你幾乎把這兒的地給翻過來了，但沒有發現任何東西。\n";
        obj = new( OBJS "button" );
        obj->move( this_object() );
        button = 0;
        this_player()->set_explore("eastland#27");
        return "你在牆角的地方發現一個金光閃閃的小東東。\n";
}
