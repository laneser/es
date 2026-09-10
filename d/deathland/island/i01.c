
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("beach of GreyIsland","灰暗之島的沙洲");
  set_long(@Long
Long
,@CLong
在這個地方你能看到一個很奇怪的現像, 除了險惡的河流之外, 正東邊是一個可
怕的沼澤, 而東南方是一個黑暗的森林, 而東北方有一條小徑, 通往北方的山嶽. 這
裡剛好就是所有地形的交會處.
地面上有一個告示牌(plaque), 上面還有一個很大的號角(horn). 旁邊有一顆巨大的
植物, 它的上面佈滿了觸手.
CLong
);

set("c_item_desc",([
    "river":"這河流的流速非常非常的快.\n",
    "horn" :"一個很大的號角\n",
    "plaque":"假如你想通過死亡之河回到原來的地方,請吹(blow)號角.\n",      
    "plant":"一顆很奇怪的植物.\n",      
           ]) );

set("exits",([
     "east":Deathland"/island/swamp01",
     "northeast":Deathland"/island/mountain01",
     "southeast":Deathland"/island/forest01",
     ]) );
set("no_monster",1);
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
    
    write("一條奇怪的觸手, 把你整個人拉起來, 並且觸手迅速的往前彈, 你\n"
          "整個人就這樣越過了河面,回到了對岸.\n"
         );
    this_player()->move_player(Deathland"/dwarf/river03",({
        "","%s被一個奇怪的觸手彈走了.\n","","%s從空中掉了下來.\n"
        }),"");      
    this_player()->set_explore("deathland#23");
    return 1;     
}
