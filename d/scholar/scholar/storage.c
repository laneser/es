#include <mudlib.h>

//inherit ROOM;

inherit "/std/room/std_storage.c";

void create()
{
	::create();
	set_short("儲藏室");
	set_long(@LONG
這裡是一間儲藏室，地上散落著一些武器和裝備，這是為了讓公會中的書生
能夠更團結而設的，也是為了能夠讓書生們有飲水思源之心，能長存己利利人、
己達達人的胸懷，牆上有貼一張告示(note)。
LONG
	);
 /*       
        set( "item_desc", ([
             "note": "儲藏室是用來放武器防具容器等重要物資的,空間有限\n"
                     "請不要當垃圾堆般的堆放無用途的東西。\n"
           ]) );
*/
	set("exits", ([
		"down"	: "/d/scholar/scholar/embattle_room",
		]) );
        set("light",1);
     //   set("container_res",1);
       set("weapon_res",({20,13}));
       set("armor_res",([
                         "body" : 20   , "legs"   : 7 ,
                         "feet" : 6    , "cloak"  : 8 ,
                         "head" : 5    , "arms"   : 4 ,
                         "misc" : 6    , "finger" : 5 ,
                         "hands" : 5   , "globe"  : 23 ,
                         "shield" : 6  , "saddle" : 9 ,
                         "kernal" : 4  , "tail"   : 8 ,
                         "others" : 6,
                         ]) ) ;
        set("max_amount",50);
        set("class_name","scholar");
        set("msg_arg","老貓");
        reset();  
}

