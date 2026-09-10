#include "../island.h"

inherit IMON+"tattack.c";

void create()
{
        ::create();
        set_level(6);
        set_name( "turtle", "巨龜" );
        set_short("巨龜");
        set("unit","只");
        set_long(@LONG
本島特產，大型海龜，不過據說山上也有
LONG
        );
        set_perm_stat("str", 8);
        set_perm_stat("dex", 8);
        set("max_hp",100);
        set("hit_points",100);
        set("wimpy",50);
        set("pursuing",1);
        set ("natural_weapon_class1", 5);
        set ("natural_min_damage1", 3);
        set ("natural_max_damage1", 8);
        set ("natural_armor_class", 20);
        set ("likefish",1);
        set_c_verbs(({"%s用整個身體向%s撞來","%s用它的硬殼向%s攻擊"}));
        set_c_limbs(({"尾巴","殼","腳部","頭部"}));      
}
