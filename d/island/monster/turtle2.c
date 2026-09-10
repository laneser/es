#include "../island.h"

inherit IMON+"tattack.c";

void create()
{
        ::create();
        set_level(3);
        set_name( "turtle", "小龜" );
        set_short("小龜");
        set("unit","只");
        set_long(@LONG
本島特產，大型海龜，不過據說山上也有，它還年輕不要欺負它！
LONG
        );
        set_perm_stat("str", 4);
        set_perm_stat("dex", 4);
        set("max_hp",65);
        set("hit_points",65);
        set("wimpy",30);
        set("pursuing",1);
        set("likefish",1);
        set ("natural_weapon_class1", 4);
        set ("natural_min_damage1", 2);
        set ("natural_max_damage1", 6);
        set ("natural_armor_class", 15);
        set_c_verbs(({"%s用整個身體向%s撞來","%s用它的硬殼向%s攻擊"}));
        set_c_limbs(({"尾巴","殼","腳部","頭部"}));      
}
