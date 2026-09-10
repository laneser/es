#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Combat Headband","樹雷戰鬥頭帶");
      add("id",({"headband"}) );
      set_short("樹雷戰鬥頭帶");
      set_long(@LONG
這是樹雷王家男性傳統的頭帶，是由罕見的冰蠶絲編織而成；由於質地輕巧，觸感
柔細，深受王族的喜愛; 通常由女性編織送給自己愛慕的男性，祈求使用者能常保
平安！
LONG
              );
      set("unit","條");
      set("type","head");
      set("material","wood");
      set("armor_class",6);
      set("defense_bonus",1);
      set("weight",20);
      set("value",({50,"gold"}) );
}              
                    
