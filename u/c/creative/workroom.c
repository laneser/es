#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        ::create();
 set_short( ""+HIW"天堂別墅"+NOR"" );
        set_long("這是全能的"+HIR"神"+NOR"--全能創世者的別墅，來到這裡你感
     到周身通泰，別墅裡的東西你從來沒見過,留心一點找找可能會有大收穫!\n");
        set( "light",1 );
        set( "exits", ([
"pray" : "/d/noden/farwind/charch",
"mage" : "d/mage/tower/mage_guild",
"knight" : "d/knight/fortress/knight_guild",
      "guild" : "/d/wiz/wiz_hall",
       ]) );
}
