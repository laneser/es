#include "../island.h"

inherit IMON+"tattack.c";

void create()
{
        ::create();
        set_level(11);
        set_name( "turtle", "壯年龜" );
        set_short("壯年龜");
        set("unit","只");
        set_long(@LONG
本島特產，大型海龜，不過據說山上也有，它現在正值壯年。
LONG
        );
        set_perm_stat("str", 14);
        set_perm_stat("dex", 14);
        set ("max_hp",200);
        set ("hit_points",200);
        set ("wimpy",100);
        set ("pursuing",1);
        set ("likefish",1);
        set ("natural_weapon_class1",11);
        set ("natural_min_damage1", 9);
        set ("natural_max_damage1", 17);
        set_natural_armor( 33,12);
        set_c_verbs(({"%s用整個身體向%s撞來","%s用它的硬殼向%s攻擊"}));
        set_c_limbs(({"尾巴","殼","腳部","頭部"}));      
}
