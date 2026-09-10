#include "../layuter.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(2);
       set_name( "brocket", "小鹿" );
        set_short( "小鹿" );
       set("unit","只");
        set_long(
       "你看見一隻可愛的動物，正在草原上輕快的散步著，他有著一對漂\n"
       "亮的小角，看起來滿溫馴的樣子。\n"
                        );
       set_perm_stat("dex", 5);
       set ("weapon_class1", 10);
       set ("armor_class", 10);
       set_c_verbs(({"%s用它的後腿向%s踢去","%s用它的角向%s撞去"}));
       set_c_limbs(({"身體","耳朵","腳部","頭部"}));
}
