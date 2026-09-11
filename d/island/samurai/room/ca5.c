#include "mercury.h"

inherit ROOM;

void create()
{
   ::create();
   set_short( "城牆" );
   set_long(
@ANGEL
你走在一個武士城堡的外圍城牆上，這個城牆很高，當你試著從城牆邊往
下看時，你會有一股心裡毛毛的感覺，因為城牆實在太高了，城牆上還有數位
看守的武士，他們對你的到來似乎有點不滿.
ANGEL
);
	set( "objects",([
	"guard#1":MOB"guard3",
	"guard#2":MOB"guard3"]));
	set("light",1);
	set_outside("eastland");
        set( "exits", ([
    "north" :MR"ca4",
    "south" :MR"ca6",
                ]) );
         reset();                     
}

