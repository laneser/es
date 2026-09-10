#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("漁村道路");
        set_long( 
@LONG
你正走在漁村的道路上，迎面撲來的是一股濃濃的腥臭味；在地上，縱橫交錯
著血水枯乾的小河；一團團蒼蠅，正汲汲於腐爛的魚肉上，不時發出嗡嗡地鳴聲。
晦暗不明的天空，烏雲團簇好似一隻只正在張牙舞爪的野獸，野獸正惡狠狠地瞪著
你，好像對著你說：『快來吧，快來吧，我的食物』。道路往東、南邊延申；北邊
有間矮矮的房子；西邊是一塊空地。
LONG);
    set( "light",1);
    set( "exits", ([
         "east":LAKE"village13",
        "south":LAKE"village11"
    ]) );
    ::reset();
}
void init()
{
   add_action("do_enter","enter");
}
int do_enter(string arg)
{
  object player;
  if ( !arg || arg!="house" )
       return notify_fail("你要進入那裡?\n");
  player=this_player();
  tell_room( this_object(),
      sprintf("%s走進屋子內。\n", player->query("c_name") ), player );
  player->move_player(LAKE"house12","SNEAK");
  tell_room( environment(player),
      sprintf("%s(%s)走了進來。\n", player->query("c_name"),player->query("name"
      ) ), player );
   return 1;
 }