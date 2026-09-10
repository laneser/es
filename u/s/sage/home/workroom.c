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
        set( "light",1 );
        set( "exits", ([
 "down" : "/u/s/sage/test/pet_shop",
  "up" : "/d/wiz/wiz_hall",
    "east" : "/u/s/sage/work.c"
        ]) );
}
