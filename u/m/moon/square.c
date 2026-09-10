//#pragma save_binary

#include "farwind.h"
#include <daemons.h>
#define BOARD FARWIND"bugsboard"

inherit ROOM ;

void create ()
{
        ::create();
        set_outside("farwind") ;
        set_short("遠風鎮廣場");
        set_long(@C_LONG
你現在來到了遠風鎮的廣場。廣場中央有一座大理石噴泉，噴泉
(fountain)旁邊立著一座鐘樓(clock) ，上面標示著時間和日期。遠
風鎮的大街穿過廣場向南北延伸，向西則是遠風鎮最繁華的微風路。
一座雄偉的英雄紀念館位於廣場的東邊。
C_LONG
        );
        set( "light", 1 );
        
        BOARD->frog();
        
        set ("exits", ([
                "north" : FARWIND"nmain",
                "south" : FARWIND"smain",
                "east" : FARWIND"bazz1",
                "west" : FARWIND"ebazz",
        ]) );
        set("water_source", 1);
        set("item_desc", ([
                "fountain" : "這座大理石噴泉正源源不絕地湧出清冽的泉水。\n"
        ]) );
        set("item_func/clock","look_at_clock");
        set("objects", (["torch"    :FARWIND"monster/dance_torch",
                         "beggar"   :FARWIND"monster/beggar",
                         "sheriff"  :FARWIND"monster/sheriff",]) );

        reset();
}
void init()
{
	add_action("do_drink","drink");
}
int do_drink(string arg)
{
	object me;

	if(!arg || (arg!="water" && arg!="泉水")) 
            return notify_fail("你要喝什麼? \n");
        me=this_player();
	if(me->query_level()<5 || wizardp(me) )
	{
		tell_object(me,"你把嘴湊向噴泉, 咕咚咕咚喝了幾口泉水.... \n"
                               "你感到渾身舒暢, 似乎體力恢復了!\n");
		tell_room(this_object(), me->query("c_name") +
                 	  "把嘴湊向噴泉, 咕咚咕咚喝了幾口泉水.... \n",
			   ({me}) );
		me->set("hit_points",me->query("max_hp"));
	}
	else return notify_fail("對不起, 只有等級小於5 的人才能在這喝水!!\n");
	return 1;
}

int look_at_clock()
{
        write( WEATHER_D->query_c_game_time()+"\n" );
        return 1 ;
}
