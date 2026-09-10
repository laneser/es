//sage 修改於  98-5-11 13:11
#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
      set_short( "書齋" );
        set_long(
             "這是一間給人讀書的房間，在房中間放著一張書桌，桌上雜亂無章，\n"
     "到處都是書本。\n"
        );
        set("exit_suppress",({"down"}));
        set( "light",1 );
        set( "exits", ([
    "down"    : "/u/s/sage/test/charch1.c",
    "up"      : "/d/wiz/wiz_hall",
    "east"    : "/u/s/sage/home/work.c",
    "healer"  : "/d/healer/building/healer_guild.c",
    "knight"  : "/d/knight/fortress/knight_guild.c",
    "mage"    : "/d/mage/tower/mage_guild.c",
    "monk"    : "/d/monk/guild/monk_guild.c",
    "scholar" : "/d/scholar/scholar/scholar_guild.c",
    "thief"   : "/d/thief/hall/thief_guild.c",
    "killer"  : "/d/killer/guild/killer_guild.c",
        ]) );
}
