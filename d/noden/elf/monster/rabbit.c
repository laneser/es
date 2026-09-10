#include "../layuter.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(1);
       set_name( "rabbit", "兔子" );
        set_short( "兔子" );
       set("unit","只");
        set_long(
       "你看見一隻可愛的動物，正在草原上輕快的跳躍著，他有著一雙\n"
       "長長的耳朵及兩隻突出的門牙，此刻它正望著你，無辜的表情好像是\n"
        "俏皮的精靈般地令人又疼又愛。\n"
                        );
       set_perm_stat("dex", 3);
       set ("weapon_class1", 3);
       set ("armor_class", 5);
       set_c_verbs(({"%s用它的後腿向%s踢去"}));
       set_c_limbs(({"身體","耳朵","腳部","頭部"}));
}
