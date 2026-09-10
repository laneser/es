#include "../layuter.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(3);
       set_name( "marmot", "土撥鼠" );
        set_short( "土撥鼠" );
       set("unit","只");
        set_long(
       "你看見一隻可愛的動物，正從地洞裡偷偷的望著你，當你走過去想\n"       
      " 撫摸它時，他飛快的躲入洞裡，一副怕羞的模樣\n"
                        );
       set_perm_stat("dex", 2);
       set ("natural_weapon_class1", 4);
       set ("natural_min_damage1",8);
       set ("natural_max_damage1", 11);
       set ("natural_armor_class", 15);
       set_c_verbs(({"%s用它的前爪向%s抓去","%s用它的牙齒向%s咬去"}));
       set_c_limbs(({"身體","腳部","頭部"}));
}

