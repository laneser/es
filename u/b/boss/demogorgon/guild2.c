#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        ::create();
      set_short( ""+HIW"PK會場"+NOR"" );
set_long(
"這是玩家專用的PK場地，這兒滿地"+HIR"鮮血"+NOR"、"+HIW"屍體"+NOR"。\n"NOR,
"一定有許多玩家死在這兒，看起來極恐怖。突然，\n"
""+HIB"死神"+NOR"對你邪惡一笑。\n"NOR,
        );
        set( "light",1 );
        set( "exits", ([
    "east" : "/u/b/boss/demogorgon/demogorgon.c",
        ]) );
}
