#include <mudlib.h>
#include "../legend.h"
inherit ROOM;

void create()
{
    ::create();
    set_short( "plain0", "古木小徑" );
    set_long(@C_LONG
你來到了一條古木小徑的盡頭。小徑的兩旁有一排排不知名的樹木，樹枝擋住
了陽光，顯得有些陰涼，樹上一些鳥兒正啾啾地叫著。在你西邊有一間小木屋。
C_LONG
    );
    set( "light",1);
    set("c_item_desc",([
     "house":"一間用繪木做成的屋子，你可以進去看看 ( enter )。\n"
    ]) );
    set( "exits", ([
     "south":LAKE"village2"
    ]) );
    reset();
}
void init()
{
   add_action("do_enter","enter");
}
int do_enter(string arg)
{
   if ( !arg || arg!="house" )
       return notify_fail("你要進入那裡?\n");
   this_player()->move_player(LAKE"house1",({
      "%s進入了一間小木屋。\n",
      "%s從外面走了進來.\n"}),"");
   return 1;
}