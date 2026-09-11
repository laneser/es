#include "mercury.h"
inherit ROOM;

void create()
{
   ::create();
   set_short( "旅店二樓" );
   set_long(@ANGEL
這裡是旅店二樓的一個小房間，由是在二樓，由日光射入，採光較
一樓好多了，窗戶旁種有一些花朵．　
ANGEL

   
         );
	set( "light",1);
	set( "objects",([
    "nakoruru":MOB"nakoruru",
    "eagle"   :MOB"eagle"
           ]));			
        set( "exits", ([
    "down":MR"mar09",    
                ]) );                   
         reset();                     
}

