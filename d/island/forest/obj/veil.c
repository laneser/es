#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Plume Veil","音羽面紗");
      add("id",({"plume","veil"}) );
      set_short("音羽面紗");
      set_long(@LONG
這是樹雷王家女性傳統的面紗，是由罕見的冰蠶絲絞白金線編織而成；由於質地輕
巧，觸感柔細，深受王族的喜愛；當使用者戰鬥意志高漲時，它就能與之呼應產生
金屬般的強度。
LONG
              );
      set("unit","條");
      set("type","head");
      set("material","light_metal");
      set("armor_class",6);
      set("defense_bonus",1);
      set("weight",20);
      set("value",({50,"gold"}) );
}              
                    
