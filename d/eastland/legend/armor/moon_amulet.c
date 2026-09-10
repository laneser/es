#include <mudlib.h>

inherit ARMOR;

void create()
{
      set_name("moon amulet","月符");
      add("id",({"amulet"}) );
      set_short("月符");
      set_long(@C_LONG
一張繡工精細的墨綠色護符。在護符上有輪滿月，而底邊的墨色把它襯托得更加皎
潔明亮，好似個含羞待放的少女，那樣地純潔無瑕。月符出處已不可考，不過根據
東方大陸一位國師的說法，如果是經過月光洗禮的魔法護符對於抗拒邪惡有莫大的
效力。　　
C_LONG
      );
      set("unit","張");
      set("type","misc");
      set("material","cloth");
      set("defense_bonus",4);
      set("special_defense",(["evil":40]) );
      set("weight",1);
      set("value",({120,"gold"}) );
}