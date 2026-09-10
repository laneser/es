#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        ::create();
      set_short( "波士的別墅" );
        set_long(
             "這是一間整整齊齊的房間，沒有一點灰塵，可能是\n"
             ""+HIW"波士女友"+NOR"常來整理的原故吧!\n"NOR,
        );
        set( "light",1 );
        set( "exits", ([
    "up"      : "/d/wiz/wiz_hall",
    "healer"  : "/d/healer/building/healer_guild.c",
    "knight"  : "/d/knight/fortress/knight_guild.c",
    "mage"    : "/d/mage/tower/mage_guild.c",
    "monk"    : "/d/monk/guild/monk_guild.c",
    "scholar" : "/d/scholar/scholar/scholar_guild.c",
    "thief"   : "/d/thief/hall/thief_guild.c",
        ]) );
}
