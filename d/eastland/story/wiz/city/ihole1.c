#include "../../story.h"

inherit ROOM;
int mob=1;
int ice_wall=0;
void create()
{
        ::create();
	set_short("洞穴");
	set_long( @LONG
你正站在一個四周都是冰壁的洞穴裡，這裡比起外面的冰原，要溫暖的多了。
上邊的頂壁是大小不一的冰錐，有的業己垂到地面形成冰柱，更有的冰柱在中間斷
折於地面上留下冰筍，情形有點像在石鐘乳洞，只不過是石灰質換成冰霜。在地上
還有些奇奇怪怪的刮痕，那刮痕好像是動物的足跡。
LONG
	);
        set("pre_exit_func", ([
          "north":"can_pass"
        ]) );
        set( "exits", ([ 
           "out" : SCITY"ice2",
        ]) );
	reset();
}
int can_pass()
{
    object guard;
    if ( !guard=present("ice-monster",this_object()) ) return 0;
    write("雪山靈魅攔住了你的去路！\n");
    return 1;
}
void init()
{
   add_action("do_search","search");
   add_action("do_hack","hack");
}
int do_hack(string arg)
{
   object ice;
   if (!ice_wall) return 0;
   if( !arg || arg!="ice_wall" )
      return notify_fail( "你想要劈開什麼東西?\n" );
   if ( this_player()->query_perm_stat("str") < 15 )
      return notify_fail( "該死，你的力量不夠。\n" );
   write("你費盡九牛二虎之力往冰壁一劈..\n");
   tell_room(this_object(),"\n忽然，從破壁裡蹦出一隻怪物來！！\n\n");
   mob=0;
   ice_wall=0;
   set("exits/north",SCITY"ihole2");
   ice=new(SWMOB"icewoman1");
   ice->move(this_object());
   return 1;
}
int do_search(string arg)
{
   if ( !mob ) return 0;
   write("你發現了一面冰壁(ice_wall)，力氣不夠是無法將它劈開(hack ice_wall)的。\n");   
   ice_wall=1;
   return 1;
}
void reset()
{
   object ob,atk;
   int i;
   mob=1;
   ice_wall=0;
   delete("exits/north");
   if ( atk=present("ice-monster",this_object()) ) atk->remove();
   ::reset();
}
