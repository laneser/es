//公會門口的廣場
#include <mudlib.h>

inherit ROOM;
inherit DOORS;

void create()
{
        ::create();
     set_short( "廣場" );
        set_long(
       "一個漂亮的噴水池坐落在廣場中央,泉水純淨而美麗。廣場上佈滿鴿子，\n"
  "人們或站或坐，或看或喂，呈現出一片和平的景象\n"
          );
     set( "light",1 );
     set( "exits", ([
          "north" : "/u/s/sage/home/work.c",
        "south" : "/u/s/sage/guild/killer_guild.c",
        ]) );
     create_door("south", "north", ([
                "keyword"       : ({ "tree door", "door" }),
                "name"          : "tree door",
                "c_name"        : "木門",
                "c_desc"        : "一扇破爛的木門",
                "status"        : "closed",
        ]) );

}
