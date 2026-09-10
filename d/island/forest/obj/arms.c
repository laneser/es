#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Combat Armbands","樹雷戰鬥臂環");
      add("id",({"arms","armbands"}) );
      set_short("樹雷戰鬥臂環");
      set_long(@LONG
這是樹雷王家傳統的戰鬥臂環．表面繡有王家的家紋，由於質地輕巧，深受王族喜愛;
當王族穿上它時，它就能與之產生共鳴，給予使用者十分恰當的保護!
LONG
              );
      set("unit","對");
      set("type","arms");
      set("material","element");
      set("armor_class",4);
      set("defense_bonus",1);
      set("weight",20);
      set("value",({200,"silver"}) );
}              
                    
