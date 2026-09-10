#include <mudlib.h>
#include "../legend.h"
inherit ROOM;

void create()
{
    ::create();
    set_short( "plain0", "小徑" );
    set_long(@C_LONG
你來到了一條清幽小徑,小徑的兩旁有一排排不知名的樹木,樹枝擋住了陽光,
顯得有些陰涼,樹上一些鳥兒正啾啾地叫著。 在你旁邊還有一棵參天的紅檜木,樹
幹約需要五十個人合抱的寬度,真是一棵千年神木!你不禁地抬頭一望,由然地生出
了憬仰之心。
C_LONG
    );
    set( "light",1);
    set( "exits", ([
     "up":LAKE"mountain8",
     "east":LAKE"plain1"
    ]) );
    set( "c_item_desc", ([
     "tree" : @C_LONG
這是一棵千年神木，如果你累了，或許可以倚在樹幹旁睡個覺(sleep)。
C_LONG
    ]) );
    reset();
}
void init()
{
   add_action("do_sleep","sleep");
}
int do_sleep(string arg)
{
   tell_object(this_player(),
      "你坐在地上倚著神木小憩一番....\n");
   this_player()->set_temp("block_command",1);
   call_out("back",7,this_player());   
   return 1;    
}   
void back(object player)
{
   player->delete_temp("block_command");
   tell_object(player,"咦，你醒來時居然身處在一個樹洞裡...\n");
   player->move(LAKE"tree1","SNEAK");
}