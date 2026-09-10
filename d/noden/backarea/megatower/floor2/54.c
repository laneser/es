#include "../megatower.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("The stair of Mega Tower","摩天塔的階梯");
  set_long(@Long
Long
,@CLong
你到達了摩天塔的第二層, 一堆亂石與破瓦堆積與此, 這裡有一個階梯, 通往第
三層.
CLong
);
  set("exits",([
               "up"    :Megatower"/floor3/45",
               "west"  :Megatower"/floor2/44",
             ]));

::reset();
}

