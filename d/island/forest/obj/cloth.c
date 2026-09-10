#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Combat Cloth","樹雷戰鬥裝");
      add("id",({"cloth"}) );
      set_short("樹雷戰鬥裝");
      set_long(@C_LONG
這是樹雷王家傳統的戰鬥裝，外觀雖然不十分起眼，由於質地輕巧，深受王族的喜愛;
當王族穿上它時，它就能與之產生共鳴，給予使用者十分恰當的保護!
C_LONG
              );
      set("unit","件");
      set("type","body");
      set("material","element");
      set("armor_class",25);
      set("defense_bonus",2);
      set("weight",130);
      set("value",({1500,"silver"}) );
}