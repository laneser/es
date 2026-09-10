#include "../asterism.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(3);
       set_name( "monkey", "猴子" );
       set_short( "monkey","猴子");
       set("unit","只");
       set_long("",
       "這隻猴子吊在樹上晃啊晃，還不時轉頭窺看你的行動。\n"       
       "你看，它又瞪著鼓露露的大眼望著你了。\n"
                        );
       set_perm_stat("dex", 2);
       set ("natural_weapon_class1", 4);
       set ("natural_min_damage1",5);
       set ("natural_max_damage1", 8);
       set ("natural_armor_class", 13);
       set_c_verbs(({"%s用它的手向%s抓去","%s用它的牙齒向%s咬去"}));
       set_c_limbs(({"身體","腳部","頭部"}));
}

