#include "mudlib.h"

void create(object ob)
{
        if ( !ob ) return ;
        ob->set_level(4);
        ob->set_name( "antelope", "麋鹿" );
        ob->set_short( "麋鹿");
        ob->set("unit","只");
        ob->set_long(@C_LONG
你看見一隻奇特的動物，頭上長著兩隻分歧的角，有著棕色的毛皮。
此時它正在森林中悠閒的漫步著
C_LONG
        );
        ob->set_perm_stat("dex", 10);
        ob->set_perm_stat("kar", 8);
        ob->set("max_hp",180);
        ob->set("hit_points",180);
        ob->set_natural_weapon(7,4,9);
        ob->set_natural_armor(25,0);
        ob->set_c_verbs(({"%s用它的角向%s攻擊","%s用它的腳向%s踢去"}));
        ob->set_c_limbs(({"身體","腳部"}));
}
