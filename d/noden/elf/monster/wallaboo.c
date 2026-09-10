#include "../layuter.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(4);
        set_name( "wallaboo", "袋鼠" );
        set_short( "袋鼠" );
        set("unit","只");
        set_long(
        "你看見一隻蹦蹦跳跳的動物在草原上愉快地遊玩\n"  
        );
        set_perm_stat("str", 8);
        set_perm_stat("dex", 8);
        set ("natural_weapon_class1", 5);
        set ("natural_min_damage1", 3);
        set ("natural_max_damage1", 8);
        set ("natural_armor_class", 20);
        set_c_verbs(({"%s用它的後腿向%s踢去","%s用它的拳頭向%s攻擊"}));
        set_c_limbs(({"身體","耳朵","腳部","頭部"}));      
}
