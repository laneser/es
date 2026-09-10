#include "island.h"
#include <mudlib.h>

inherit ROOM;

void create()
{
      ::create();
      
      set_short("渾沌");
      set_long(@LONG
一片渾沌，不是餛飩，不能吃！
LONG
       );
}