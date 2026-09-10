
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("???","河邊");
  set_long(@Long
Long
,@CLong
目前你位於一個奇怪的地方, 除了你來的方向外, 其餘的三個方向都是可怕的河水.
有一個告示牌(plaque)立於地上, 上面還有一個很大的號角(horn).
CLong
);

set("c_item_desc",([
    "river":"這些河流的流速非常非常的快, 除此之外你發現在河流的對岸似乎\n"
            "有個小島.\n",
    "island":"一個位於河中的小島, 上面似乎有著奇怪的植物存在著, 但你並不能\n"
             "確定, 因為距離實在是太遠了.\n",        
    "horn"  :"一個很大的號角\n",
    "plaque":"假如你想通過死亡之河到達灰暗之島的話,請吹(blow)號角.\n",      
           ]) );

set("exits",([
     "west":Deathland"/dwarf/river02",
     ]) );
 ::reset();
}

void init()
{
   add_action("to_swim","swim");
   add_action("to_blow","blow");
  
}


int to_swim()
{
    write("這河水流動的太快速了,即使你的游泳技巧再好,假如你真的下河去的話,\n"
          "你將直接游到閻羅王的面前報到了.\n");
    return 1;      
} 
int to_blow(string str)
{
    if (!str|| str!="horn") return 0;
    
    write("從遙遠的對岸忽然飛來一條奇怪的觸手, 把你整個人拉起來, 並且觸手\n"
          "迅速的往後拉, 你整個人就這樣越過了河面,來到了對岸.\n"
         );
    this_player()->move_player(Deathland"/island/i01",({
        "%s被一個奇怪的觸手拉走了.\n","%s從空中掉了下來.\n"
        }),"");      
    return 1;     
}
