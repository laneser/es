#include "../oldcat.h"

inherit WEAPON;

void create()
{
     set_name("broom","掃把");
     set_short("掃把");
     set_long(
      "一把普通的掃把.你可以拿著它去掃掃灰塵.\n"
      );
     set( "unit", "把");
     set( "type","blunt");
     set("weight",35);
     set("value", ({ 20, "silver" }));
     set("weapon_class",10);
     set("min_damage",5);
     set("max_damage",15);
}
