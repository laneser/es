#include "../dony.h"

inherit WEAPON;

void create()
{
     set_name("broom","破掃帚");
     add( "id",({"broom"}) );
     set_short("破掃帚");
     set_long(@C_LONG
一把普普通通的破掃帚。除了拿來掃地之外,你看不出有什麼功用。
C_LONG
      );
     set( "unit", "把");
     set("weight",30);
     set("value", ({ 25, "silver" }));
     setup_weapon( "blunt", 30, 15, 30 );
}
