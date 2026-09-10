#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(16);
       set_name( set_color("Crab","HIR"),set_color("小螃蟹","HIR") );
       add("id",({"crab"}) );
       set_short( set_color("小螃蟹","HIR") );
       set("unit","只");
       set_long(set_color("
    
      ∪        ∪
     □ ⊙  ⊙ □
    《\\┴—┴/《    　一隻全身赤紅的小螃蟹，它正向你炫著它的兩個大
    《｜    □《　　   巨螯。
     □———□


       \n","HIR"));
       set_perm_stat("str",25);
       set_natural_armor(75,0);
       set_natural_weapon(27,18,29);
       set_c_verbs(({"%s用它的巨螯向%s攻擊"}));
       set_c_limbs(({"身體","頭部","殼"}));
}

