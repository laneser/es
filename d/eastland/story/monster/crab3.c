#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(4);
       set_name( set_color("Crab","HIG"), set_color("小螃蟹","HIG") );
       add("id",({"crab"}) );
       set_short( set_color("小螃蟹","HIG") );
       set("unit","只");
       set_long(set_color("
    
      ∪        ∪
     □ ⊙  ⊙ □
    《\\┴—┴/《    一隻全身青色的小螃蟹，它正瞪著你瞧，小小的眼睛
    《｜    □《　　 ，模樣可愛極了。  
     □———□

       
       \n","HIG"));
       set_natural_armor(20,0);
       set_natural_weapon(5,3,6);
       set_c_verbs(({"%s用它的螯向%s攻擊"}));
       set_c_limbs(({"身體","頭部","殼"}));
}

