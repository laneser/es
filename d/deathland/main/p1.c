
#include "../echobomber.h"
inherit ROOM;

void create()
{
        ::create();
        set("light",1);
        set_short("黑暗沼澤");
        set_long(@Long_Description
一個充滿奇怪植物的沼澤,你的腳似乎不能很順利的移動.而那些奇怪的植物正伸
著它的觸手到處尋找食物,這沼澤是一個非常危險的地方.
在北方懸崖有一個很深的洞穴(hole),但是你不確定他通向何處.
Long_Description
 );
  set("item_desc",([
      "cliff":"很高的懸崖.有很多的蔓藤植物依附在上面.\n",
      "hole":"一個很深的洞穴.\n",
      "plants":"一些奇怪的植物.\n",
                     ]) );

  set("exits",([
    "southwest":Deathland"/main/d1",
   ]));
}

void init()
{
     add_action("to_enter","enter");
}

int to_enter(string str)
{
   if (!str||str!="hole") return 0;
 
   write( 
           "你掉入這深深的洞穴.\n");
   this_player()->move_player(Deathland"/main/d2.c",
      ({
      "%s掉入洞中而消失.\n",
        "%s從上面的洞中掉了下來.\n"}),"");
   return 1;

}
