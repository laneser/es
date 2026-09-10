// Echo/item/broom.c

#include "../echobomber.h"
inherit OBJECT;

void create()
{
     set_name("broom","掃把");
     set_short("a broom","掃把");
     set_long(
      "just a broom.\n",
      "一把普通的掃把.你可以拿著它去掃掃灰塵.\n"
      );
     set( "unit", "把");
     set("weight",35);
     set("value", ({ 10, "silver" }));
}
