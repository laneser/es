
#include "mudlib.h"

inherit MONSTER;

void create ()
{
       ::create();
       set_level(4);
       set_name( "deer", "鹿" );
       set_short("鹿");
       set("unit","只");
       set_long(@C_LONG
你看見一隻可愛的動物，正在草原上輕快的散步著，它有著一對漂
亮的長角，看起來滿溫馴的樣子，一點都不怕人。
C_LONG
                        );
       set_perm_stat("dex", 10);
        set_natural_armor( 25, 6 );
        set_natural_weapon( 8, 4, 7 );
       set ("armor_class", 20);
       set_c_verbs(({"%s用它的後腿向%s踢去","%s用它的角向%s撞去"}));
       set_c_limbs(({"身體","耳朵","腳部","頭部"}));
#include <replace_mob.h>
}
