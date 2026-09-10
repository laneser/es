#include "/d/eastland/beggar/dony.h"
//inherit "/d/eastland/beggar/area/ch_stun.c";
inherit ROOM;
void create()
{
	object mob;
	::create();
        set_short( "north2", "村路" );
     	set_long(@C_LONG
你現在正走在一條頗為寬大的村路上,約可容納兩匹馬並行。村路向南、北方
向延伸。這條村路整理得蠻乾淨的,路旁的植物修緝的很整齊,花兒欣欣向榮,比起
廣場那片光禿禿的景像自是不可而語。畢竟這條是連接幾個較大鋪子,可說是村內
最繁華的道路。雖是如此, 卻看不出任何人工刻意留下來的痕跡,這一定是出自於
某位名匠之手。西邊是一家打鐵鋪。
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
                      "west":DBEGGAR"smith.c",
                      "south":DBEGGAR"north1.c",
	              "north":DBEGGAR"north3.c"
	]) );
        mob=new(DMONSTER"soothsayer");
        mob->move(this_object());
     reset();
}
void init()
{
    add_action("do_backstab","backstab");
}
int clean_up()
{
    return 0;
}        
void do_backstab(string str)
{
    object temp;
   if (str){
      tell_object(this_player(),
       "想 bs ? 別傻了。\n");
      this_player()->set_temp("block_command",1);
      call_out("recover1",5,this_player());
      return ;
   }
      return ;
}
void recover1(object obj)
{
     obj->delete_temp("block_command");
     tell_object(obj,
         "除了 bs 之外,難道沒有別的方法?\n");
}
