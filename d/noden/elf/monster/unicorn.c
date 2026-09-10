#include "../layuter.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(18);
       set_name( "unicorn","獨角獸");
        set_short( "獨角獸" );
       set("unit","只");
        set_long(
       "這是一隻神獸，它有著駿馬似的身軀，及一隻奇特的角，請\n"
       "不要傷害它，因為有傳說若有人傷害它 ，上天將會降禍於世人\n" );
       set_perm_stat("dex", 30);
       set("natural_weapon_class1",35);
       set("natural_armor_class", 80);
       set_perm_stat("str",20);
       set_perm_stat("kar",25);
       set_perm_stat("int",20);
       set_perm_stat("pie",20);
       set_skill("dodge",100);
       set("natural_defense_bonus",24);
       set("alignment",2000);
       set("max_hp",500);
       set("hit_points",500);
       set("natural_min_damage1",19);
       set("natural_max_damage1",35);
       set_c_verbs(({"%s用它的後腿向%s踢去","%s用它的角向%s頂去"}));
       set_c_limbs(({"身體","尾巴","腳部","頭部"}));
}
