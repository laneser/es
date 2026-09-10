#include <mudlib.h>

inherit WEAPON;

void create()
{
     set_name("fish blunt","釣杆");
     add( "id",({"blunt"}) );
     set_short("釣杆");
     set_long(@C_LONG
一根普通的釣杆，上面有著千百條的刮痕。
C_LONG
      );
     set( "unit", "根");
     set("weight",90);
     set("value", ({ 250, "silver" }));
     setup_weapon( "blunt", 20, 8, 15 );
}
