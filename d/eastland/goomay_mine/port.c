
#include <zeus.h>

inherit ROOM;

void create()
{
  ::create();
  set_short("橋下");
  set_long(@CLong
這裡是竹橋的正下方，有幾截木頭靠在河岸邊，互相撞擊著．從網子 (net)
上可以明顯的看出它磨損的很厲害，有幾個工人正忙著把一袋袋的東西裝在板車
上，由車痕可看出這些貨物很重．水是東向西流的，不知道河 (river)上游的情
形如何？
CLong
);
   

set("exits",([
             "up" :ZROOM"/bridge"    ]));
set("item_desc",([
	"net" : "一個不可能拿來捕魚的網子，它的網眼實在太大了．\n",
	"river" : "一條湍急的河流．\n"
	]));
		             
set("objects",([
             "Dun gin" : ZMOB"/Dun_gin"  ]));
reset();
 }
void init()
 {
 add_action("do_swim","swim");
 }
 int do_swim(string str)
 {    int sk;
      sk=(int)this_player()->query_skill("swimming");
      if(random(sk) < 30 ) {
      write("\n你一招魚躍龍門向水裡射去,卻抵不住河流的猛勁,被衝回來了\n");
      tell_room(environment(this_player()),(
             this_player()->query("c_name")+"以美妙的姿勢跳進河裡,卻狼狽的從網子下爬了出來\n"),
             this_player() );
         return 1;
          }
      else{
      write("\n你努力地抓住出水口處的石頭，看了一看，突然一根木頭向你打來，\n"
            "\n想必是哪位巫師在開玩笑！游進去不被亂棒打死才怪\n");
      tell_room(environment(this_player()),(
              this_player()->query("c_name")+"以美妙的姿勢跳入河裡，卻失望地爬了起來\n"),
              this_player() );
         return 1;}
 }          