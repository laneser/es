
#include <mudlib.h>
inherit OBJECT;

void create()
{
       set_name("evil dagger","邪惡匕首");
       set_short("evil dagger","邪惡匕首");
       add("id",({"dagger"}));
       set_long(@C_LONG
這柄匕首的握柄上畫有一條有八條尾巴的怪物，刀鋒黝
黑，極其銳利，並且散發出一陣陣邪氣，由於邪氣逼人
，依你的經驗，這並不適合做為你戰鬥用的武器。
C_LONG );
      set("unit","柄");
      set("weight",8);
      set("no_sale",1);
      set("no_clean",1);
      set("value",({410,"silver"}));
}
