#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Combat Feet","樹雷戰鬥靴");
      add("id",({"boots","feet"}) );
      set_short("樹雷戰鬥靴");
      set_long(@C_LONG
這是樹雷王家傳統的戰鬥靴，表面繡有王家的家紋，由於質地輕巧，深受王族喜愛; 
當王族穿上它時，它就能與之產生共鳴，給予使用者十分恰當的保護!
C_LONG
              );
      set("unit","雙");
      set("type","feet");
      set("material","element");
      set("armor_class",5);
      set("defense_bonus",2);
      set("weight",30);
      set("no_sale",1);
      set("value",({300,"silver"}) );
}              
                    
