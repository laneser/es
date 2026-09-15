#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(6);
       set_name( set_color("Crab","HIY"),set_color("小螃蟹","HIY") );
       add("id",({"crab"}) );
       set_short( set_color("小螃蟹","HIY") );
       set("unit","只");
       set_long(set_color("
    
      ∪        ∪
     ﹨ ⊙  ⊙ ∕
    ︽\\┴─┴/︽    　一隻全身黃色的小螃蟹，不知道是屬於什麼種類。
    ︽︳    ▕︽　　   它現在正在補食。
     ╰───╯

       
       \n","HIY"));
       set_natural_armor(30,0);
       set_natural_weapon(9,5,9);
       set_c_verbs(({"%s用它的螯向%s攻擊"}));
       set_c_limbs(({"身體","頭部","殼"}));
}

