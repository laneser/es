
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("house of truffle","木菰種植室");
  set_long(@Long
Long
,@CLong
這裡到處都是一排排的木架,而上面種滿了木菰(truffle),一種美味的食物.矮人們花了
\許久才發現了種植的方法,就是把它種在陰暗潮溼的地底.由此可見這裡離開地表的深度.
CLong
);

set("c_item_desc",([
    "truffle":"木菰,一種美味的食物.\n",
   ]) );
set("exits",([
     "southup":Deathland"/dwarf/pass02.c",
     ]) );
 ::reset();
#include "../replace_room.h"
}

