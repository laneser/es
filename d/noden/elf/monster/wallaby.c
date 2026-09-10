#include "../layuter.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(1);
        set_name( "wallaby", "小袋鼠" );
        set_short( "小袋鼠" );
        set("unit","只");
        set_long(
        "你看見一隻可愛的動物在草原上蹦蹦跳跳地遊玩著\n"  
        );
        set_perm_stat("str", 3);
        set_perm_stat("dex", 3);
        set ("natural_weapon_class1", 3);
        set ("natural_min_damage1", 2);
        set ("natural_max_damage1", 3);
        set ("natural_armor_class", 5);
        set_c_verbs(({"%s用它的後腿向%s踢去","%s用它的拳頭向%s攻擊"}));
        set_c_limbs(({"身體","耳朵","腳部","頭部"}));      
}
