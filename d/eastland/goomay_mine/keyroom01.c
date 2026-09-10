
#include <zeus.h>

inherit ROOM;
int paper_num;
void create()
{
  ::create();
  set_short("段家礦坑通道");
  set_long(@CLong
這是一條長長的通道，前面消失的鐵軌現在又出現在地上，鐵軌是南北
向的，四周用了許多木條固定，前面偶而傳來敲擊的聲音，可能快到達礦工
們採礦的地方了．通道的兩側希希落落地散佈著開採時留下的裂縫．
CLong
);
set("item_desc",(["crack":
"這是一條開採時留下的裂縫，依稀可以看到一些礦粒卡在隙縫中．\n"
    ]) ); 

set("exits",([
             "north":ZROOM"/keyroom02",
             "southwest":ZROOM"/center3"
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
    paper_num=1;
 }   
 int do_search(string str)
 {     object obj;
       if (!str||str!="crack"||(int)this_player()->query_temp("get/paper_torch")!=1) {
       write("你在搜哪裡啊？這裡這麼大可能要搜到明天喔！\n"); 
       return 1;
                                }   
       if (paper_num){
       write("聽了病人的話後，你伸手往裂縫仔細掏去，結果掏出一張奇怪的紙\n");
       tell_room(environment(this_player()),(
       this_player()->query("c_name")+"將手伸入裂縫中找尋\n"),
       this_player() );
       this_player()->set_temp("magic/paper",1);
       obj=new(ZOBJ"/paper_torch.c");
       obj->move(this_player());
       paper_num=0;
       return 1;
                     }      
}
