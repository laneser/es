#include "mumar.h"
inherit ROOM;
 
void create()
{
        ::create();
  set_short("The vault door","庫房大門");
  set_long(@Long
Long
,@CLong
這裡是牧馬關武器庫的大門，牆上貼了一堆『生人勿近』、『嚴禁煙火』之類的
標語。這兒的地面上盡是一些凌亂的腳印，你可以想見一群士兵在緊急戰備時到這來
領取裝備的景像。從這兒往東可以回到教場上，西邊就是武器庫。
CLong
);
set_outside("eastland");
set( "pre_exit_func", ([ "west" : "check_guard" ]) );
set("exits",([
               "west": MUMAR "vault01",
               "east": MUMAR "square04"
             ]));
set("objects",([
               "guard#1": MOB "guard",
               "guard#2": MOB "guard"]));
reset();
}
 
int check_guard()
{
        if( wizardp(this_player()) || !present("guard") ) return 0;
   { if(this_player()->query_temp("army_mark") )    {
        tell_object(this_player(), can_read_chinese() ?
                    "守衛說道:長官好....。同時做出持槍敬禮的動作。\n":
                    "The guard said : Good morning, Sir!" );
	this_player()->set_explore("eastland#35");
        return 0;
          }
      else   {
        tell_object(this_player(), can_read_chinese() ?
                "庫房守衛說: 那裡是本關重地，你不能進去。\n" :
                "The guard says: Sorry, you can't go there.\n" );
        return 1;
             }
}
}
