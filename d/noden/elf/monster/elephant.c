#include "../layuter.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(5);
        set_name( "elephant", "大象" );
        set_short( "大象" );
        set("unit","頭");
        set_long(
        "你看見一隻巨大的動物，有著長長的鼻子、巨大的耳朵、與兩根白色的長牙，\n"
        "此時它正在草原上悠閒的漫步著\n"  
        );
        set_perm_stat("str", 8);
        set_perm_stat("dex", 3);
        set("max_hp",100);
        set("hit_points",100);
        set ("natural_weapon_class1", 3);
        set ("natural_min_damage1", 5);
        set ("natural_max_damage1", 10);
        set ("natural_armor_class", 25);
        set_c_verbs(({"%s用它的長牙向%s攻擊","%s用它的長鼻甩向%s"}));
        set_c_limbs(({"鼻子","身體","耳朵","腳部","頭部"}));      
}
