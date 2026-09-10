#include "../dony.h"
inherit DOORS;
inherit ROOM;

void create()
{
	::create();
        set_short( "jail1", "『薪膽村』監牢" );
	set_long(@C_LONG
你現在進入了一間臭到極點的監牢，到底有多臭你也說不上來，因為你的手正
不自覺地捂著鼻子。地上有幾具還沒有腐敗完的□體和許多白森森的骨頭, 監牢的
角落裡有一張釘在牆壁上的木板床。
C_LONG
	);
	set( "light" , 1 );
	set( "exits", ([
                      "east":DBEGGAR"east10.c"
	]) );
        set( "c_item_desc", ([
                 "bed" :"一張簡簡單單的木床。\n",
                 "bone":"幾根死人的骨頭。\n"
        ]) );
                                    
        set( "objects",([  
                     "chan":DMONSTER"chan"
                     ]) );
      
        create_door( "east", "west", ([
                     "keyword" : ({ "copper door", "door" }),
                     "name" : "copper door",
                     "c_name" : "小銅門",
                     "c_desc" : "一扇很普通的小銅門",
                     "status" : "locked",
                     "lock" : "DBEGGAR_JAIL1"
                    ]) );
     reset();
}
void init()
{
   add_action("do_search","search");
}
int do_search(string arg)
{
   if( !arg || arg!= "bone" )
      return notify_fail("你要找什麼呢?\n");
         
   tell_object(this_player(),"你心裡想,原來是有暗門。\n");
   this_player()->move_player(DBEGGAR"jail2.c");
   return 1;
}      
