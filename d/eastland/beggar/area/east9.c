#include "../dony.h"

inherit ROOM;

void create()
{
	::create();
        set_short( "east9", "陰暗房間" );
	set_long(@C_LONG
你來到了一個陰暗的房間,因為這裡長久欠缺陽光的照射,所以總有股揮之不去
的發黴味道。這裡沒什麼擺設,空洞洞的,牆壁上只有幾根快燒完的火把, 地上也沒
什腳印之類的東西,畢竟這裡很少人來。
C_LONG
	);
	set("light",0);
	set( "exits", ([
                      "north":DBEGGAR"east10.c",
                      "south":DBEGGAR"east8.c"
	]) );
        set("objects",([
                      "guard1":DMONSTER"jail_guard",
                      "guard2":DMONSTER"jail_guard",
                      "guard3":DMONSTER"jail_guard",
                      "guard4":DMONSTER"jail_guard",
                      "guard5":DMONSTER"jail_guard",
                      "guard6":DMONSTER"jail_guard",
                      "guard7":DMONSTER"jail_guard",
                      "guard8":DMONSTER"jail_guard",
                      "guard9":DMONSTER"jail_guard",
                     "guard10":DMONSTER"jail_guard", 
        ]) );
        set("pre_exit_func",([
                "north":"do_show"]));
     reset();
}
void init()
{ 
   add_action("do_show","show"); 
}

int do_show( string arg )
{
   if( !present("jail guard"))
      return 0;
    
   if ( !arg || arg != "password" ){
      write(@C_LONG
守衛把你攔住不讓你過。
守衛說道說道:如果你有手諭拿給我看 ( show password ),那麼我就可以讓你過去。
C_LONG
           );
      return 1;        
   }
   
   if ( present("password",this_player()) ){
      write(@C_LONG
守衛說道:嗯,你可以過去了,不過不要做壞事。
C_LONG
            );
      this_player()->move_player(DBEGGAR"east10");
      return 1;
   }      
}