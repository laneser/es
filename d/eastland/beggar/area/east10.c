#include "../dony.h"

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
        set_short( "east8", "陰暗的房間" );
	set_long(@C_LONG
你來到一個陰暗的房間,這裡有一股屍臭味,想必以前有很多人死在這兒。這裡
沒什麼擺設,只有一張手臂長寬的桌子,桌子上有一堆被嗑完的瓜子殼, 還有一些空
酒瓶,想必是獄卒無聊的時候所遺留下來的垃圾。牆壁上有一根快要燒光的火把,不
知道為什麼,這裡給你的感覺總是陰森森的。
C_LONG
	);
	set("light",0);
	set( "exits", ([
                      "west":DBEGGAR"jail1.c",
                      "south":DBEGGAR"east9.c"
	]) );
        set( "c_item_desc", ([
            "torch" :"一根快被燒完的火把。\n"
        ]) );        
        create_door( "west", "east", ([
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
   add_action("do_touch","touch"); 
}

int do_touch( string arg )
{
     
     if ( !arg || arg != "torch" )
        return notify_fail("你要摸什麼?\n");
     
     tell_object( this_player(),
           "\n\n\n忽然間你覺得天旋地轉地倒在地上.....\n\n\n\n\n");
     call_out( "recover",20,this_player());
     this_player()->set_temp("block_command",1);
     return 1;
}

void recover(object toucher)
{
   toucher->set_temp("block_command",0);
   tell_object(toucher,"\n\n你覺得你來到了一個奇怪的地方..。\n\n\n");
   this_player()->move_player(DBEGGAR"temp_room1");
}

