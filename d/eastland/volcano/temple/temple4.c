#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("矮靈族神殿");
	set_long(
@LONG_DESCRIPTION
一間迷漫著神秘氣氛的矮靈族神殿，神殿的頂端雕有火神的圖案，四根雕
有龍紋的巨大柱子豎在四個腳落，幾個祈禱者正在對著火神的神像(statue)不
知道念著甚麼經文，在神像前的供桌(desk)有一些供品。
LONG_DESCRIPTION
	);
set( "exits", ([
     "east": OTEMP"temple6",
     "west": OTEMP"temple5",
     "south": OTEMP"temple1",
     ]) );
set("item_desc",([
    "statue":"一個栩栩如生的火神雕像，你感覺雕像的眼睛正在看著你\n",
    "desk" : @DESK
蜥蜴人的尾巴，半獸人的腦，鳥人的翅膀，連眼魔的觸腳也在其中，跟這些比較
不同的是一碗小廚師麻辣牛肉麵(beef noodle)也在供品之列。
DESK
,
    "noodle":"一碗香噴噴的牛肉麵，令你食指大動。\n",
       ]));
set( "objects", ([
     "m_enforcer" : OMONSTER"m_enforcer",
     "wprayer#1" : OMONSTER"wprayer",
     "wprayer#2" : OMONSTER"wprayer",
     "corasho": OMONSTER"corasho",
     ]) );
set("light",1);
reset();
}

void init()
{
  add_action("do_eat","eat");
}

int do_eat(string arg)
{
  object ob1;

  if (!arg || (arg!="noodle" && arg!="牛肉麵"))
      return notify_fail("\n你要吃仙桃嗎?\n");

  if (be_eated) {
    write( "\n你拿起碗一看，發現好吃的牛肉麵已經被吃掉了。\n");
    return 1;
  }

  write( "\n你趁著其他人不注意的時後，偷偷的把這碗泡麵拿起來吃掉，\n");
  write( "哇!真是人間美味．．．．．突然你發現好像咬到什麼東西，敢 \n");
  write( "緊吐出來．．．．嚇 !  竟然是一個金色巧克力。\n");
  be_eated=1;
  ob1=new(OOBJ"g_chocolate");
  ob1->move(this_object());
  return 1;
  
}

void reset()
{ 
  ::reset();
  be_eated=0;
}
