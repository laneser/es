#include "../zeus.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(15);
       set_name( "pigeon", "小鴿子" );
       set_short( "pigeon","小鴿子");
       set("unit","只");
       set_long(@LONG
你看見一隻可愛的動物，正在地上輕快的啄食著，他用一雙烏黑的
小眼睛正望著你，無辜的表情好像是在對你說，不要傷害我．
LONG
);
       set_perm_stat("dex", 20);
       set ("weapon_class1", 20);
       set ("tactic_func","my_tactic");
       set ("armor_class", 25);
       set_c_verbs(({"%s用它的尖嘴向%s刺去"}));
       set_c_limbs(({"身體","耳朵","腳部","頭部"}));
}
int my_tactic()
{  object obj;
   tell_room(environment(this_object()),
   "小鴿子回頭望了望你，然後很不屑地飛走了，彷佛在譏笑你的無知．\n"
   );
   obj=present("pigeon");
   obj->remove();
   return 1;
   }
