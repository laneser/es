#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        ::create();
      set_short( "凌風的玩具屋" );
        set_long(
             "你所看到的屋子是凌風的玩具屋，這裡看起來似乎很亂，大概是\n"
             ""+HIW"波士和創世者"+NOR"經常來搗亂，所以才會...................\n"
             "由於凌風經常不在家，所以這裡只有讓搗蛋鬼們亂搞了。\n"NOR,
        );
        set( "light",1 );
        set( "exits", ([
    "west" : "u/b/boss/workroom.c",
    "north" : "/d/mage/tower/time.c",
    "healer" : "/d/healer/building/healer_guild.c",
    "knight" : "/d/knight/fortress/knight_guild.c",
    "thief" : "/d/thief/hall/thief_guild.c",
    "mage" : "/d/mage/tower/mage_guild.c",
    "monk" : "/d/monk/guild/monk_guild.c",    
    "scholar" : "/d/scholar/scholar/scholar_guild.c",

        ]) );
}
