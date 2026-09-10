
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("On the Stair","階梯上");
  set_long(@Long
Long
,@CLong
你注意到你正站在階梯上, 這是一個東西向的階梯.  
CLong
);
set("exits",([
             "westup":Mine"/t03",
             "eastdown":Mine"/t04",
             ]));
#include <replace_room.h>
}
