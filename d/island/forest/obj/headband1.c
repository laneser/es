#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Police Headband","警用頭帶");
      add("id",({"headband","band"}) );
      set_short("警用頭帶");
      set_long(@LONG
這是魔族的保安官執行勤務時必備的裝備，上頭還印有必勝的字樣。它的形狀
很像兔子的耳朵，用來施放偵測魔法，以其能即早發現及防範犯罪。
LONG
              );
      set("unit","條");
      set("type","head");
      set("material","cloth");
      set("armor_class",6);
      set("defense_bonus",1);
      set("weight",50);
      set("value",({300,"silver"}) );
}              
                    
