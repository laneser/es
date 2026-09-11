
#include "zeus.h"

inherit ROOM;
int boxes_num;
void create()
{
  ::create();
  set_short("段家礦坑通道");
  set_long(@CLong
這是一條長長的通道，前面消失的鐵軌現在又出現在地上，鐵軌是南北
向的，四周用了許多木條固定，前面傳來敲擊的聲音越來越大，應該快到達
礦工們採礦的地方了．通道的兩側希希落落地散佈著開採時留下的裂縫和一
些放工具的箱子．
CLong
);
set("item_desc",(["crack":
"這是一條開採時留下的裂縫，依稀可以看到一些礦粒卡在隙縫中．\n",
"box" : "這是許多工具箱中的一個，沒有什麼特別的地方，找找其它的箱子吧！\n",
"boxes":"這是一些工具箱，也許可以在裡面找到一些有用的東西．\n"
    ]) ); 

set("exits",([
             "north":ZROOM"/keyroom03",
             "south":ZROOM"/keyroom01"
             ]));

reset();
}
void init()
{
 add_action("do_search","search");
 }
 void reset()
 {
    ::reset();
    boxes_num=1;
 }   
 int do_search(string str)
 {     object obj;
       if (!str||str!="boxes") {
       write("你在搜哪裡啊？這裡這麼大可能要搜到明天喔！\n"); 
       return 1;
                                }   
       if (boxes_num){
       write("你伸手把箱子翻開，結果發現一卷奇怪的紙\n");
       tell_room(environment(this_player()),(
       "你看到"+this_player()->query("c_name")+"將箱子翻開，不知道在找什麼？．\n"),
       this_player() );
       obj=new(ZOBJ"/mine_scroll.c");
       obj->move(this_player());
       
       boxes_num=0;
       return 1;
                     }
}