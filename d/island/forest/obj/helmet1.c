#include "../tsunami.h"

inherit ARMOR;

void create()
{
  set_name("Bone Helmet","龍骨盔");
  add("id",({"bone","helmet"}) );
  set_short("龍骨盔");
  set_long(@LONG
這就是傳說中用魔龍頭骨所作成的頭盔，只見它不斷的閃爍著黑色的光芒。
LONG
          );
  set("unit","個");
  set("type","head");
  set("material","stone");
  set("armor_class",5);
  set("defense_bonus",3);
  set("weight",200);
  set("value",({100,"gold"}) );
  set("no_sale",1);
}
