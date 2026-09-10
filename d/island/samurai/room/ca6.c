#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "城牆" );
   set_long(@ANGEL
你走在一個武士城堡的外圍城牆上，這個城牆很高，當你試著從城牆邊往
下看時，你會有一股心裡毛毛的感覺，因為城牆實在太高了，城牆在此改向東
邊延伸．
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");
        set( "exits", ([
    "north" :MR"ca5",
    "east" :MR"ca7",
                ]) );
         reset();                     
#include <replace_room.h>
}

