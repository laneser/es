#include "../tsunami.h"

inherit ARMOR;

void create()
{
  set_name("Turtle Boots","神龜戰靴");
  add("id",({"turtle","boots"}) );
  set_short("神龜戰靴");
  set_long(@LONG
這就是傳說中用神龜的龜甲所作成的戰靴。
LONG
          );
  set("unit","雙");
  set("type","feet");
  set("material","stone");
  set("armor_class",8);
  set("defense_bonus",2);
  set("weight",100);
  set("value",({200,"gold"}) );
}
