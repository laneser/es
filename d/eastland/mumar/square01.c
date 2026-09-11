#include "mumar.h"
inherit ROOM;
int cockroach = 1;
int fragment = 1;
 
void create()
{
        ::create();
  set_short("牧馬關教場");
  set_long( @CLong
這兒是教場的西南角落，由於長滿了青苔，使得城牆看起來像是上了綠漆一般，
你彷佛聽見一陣陣的腳步聲和談話聲從城牆上傳來。牆角整齊地堆積著一些雜物和箱
子(box) ，地面上則還有一些燃燒過的痕跡。
CLong
);
  set( "c_item_desc", ([
                "box" : @LONG_TEXT
這些箱子上都寫著「軍用品」、「小心輕放」之類的字眼，不過不知道放在這兒
多久了，經過風吹雨打日曬，有些已經腐朽變形了。
LONG_TEXT
 ]) );
set_outside("eastland");
set("exits",([
               "north": MUMAR "square04",
               "east": MUMAR "square02" ]));
set( "search_desc", ([ "box" : "@@search_box","corner": "@@search_corner" ]) );
        reset();
}
 
string search_box()
{
        object obj;
 
        if( !cockroach || present("cockroach", this_object()) ) return
        "你把所有的箱子都翻了一遍，但是什麼都找不到。\n";
        obj = new( MOB"cockroach" );
        obj->move( this_object() );
        cockroach = 0;
        return
        "你開始翻箱倒櫃地找東西，忽然跑出了一個黑色毛茸茸的東西...嚇！蟑螂！\n";
}
 
string search_corner()
{
        object obj;
 
        if( !fragment || present("fragment", this_object()) ) return
          "你在角落裡找了半天，但是連個石頭都沒有看到。\n";
        obj = new( OBJS"fragment" );
        obj->move( this_object() );
        fragment = 0;
        return
         "你在角落裡開始翻箱倒櫃地找東西，終於找到了一片碎鏡子！\n";
}
