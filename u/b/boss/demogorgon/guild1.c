#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        ::create();
      set_short( "技術進修場" );
set_long(
"好多"+HIB"魔神戰士"NOR"走來走去，大家都在努力的進修自己。\n"
"希望成為最終的"+HIR"強者"+NOR"。\n"
  NOR
        );
        set( "light",1 );
        set( "exits", ([
    "west" : "/u/b/boss/demogorgon/demogorgon.c",
        ]) );
}
