#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Police boots","警用振暴鞋");
      add("id",({"boots","feet"}) );
      set_short("警用振暴鞋");
      set_long(@C_LONG
魔族保安官專用的振暴鞋，不但可以用來增加美觀，更可在擒拿時隔開對方的
武器，是警維護城內治安時的最佳裝備。
C_LONG
              );
      set("unit","雙");
      set("type","feet");
      set("material","cloth");
      set("armor_class",5);
      set("defense_bonus",1);
      set("weight",100);
      set("value",({500,"silver"}) );
}              
                    
