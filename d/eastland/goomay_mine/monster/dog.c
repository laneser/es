#include "../zeus.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(11);
       set_name( "dog", "蓬萊犬" );
       set_short( "dog","蓬萊犬");
       set("unit","只");
       set_long(@LONG
一隻負責看守竹橋的忠狗－小馨
LONG
);
       set_perm_stat("dex", 20);
       set_perm_stat("str",18);
       set_perm_stat("kar",15);
       set_natural_weapon(20,10,20);
       set_natural_armor(50, 15);
       set_c_verbs(({"%s用它的嘴向%s咬去"}));
       set_c_limbs(({"身體","耳朵","腳部","頭部"}));
       set("killer",1);
       set("chat_chance",20 );
       set("att_chat_output",({
                "蓬萊犬不停的狂吠:汪！　汪！　汪汪！\n"
                }));
                }
void die()
{
     tell_room(environment(this_object()),
@DIE

段老大突然急忙的跑了出來叫道:住手！住手！　可憐的小馨你竟然被人欺負
成這個樣子，放心好了我一定不會讓你白死的.
段老大忿然地轉身離去，只留下一句話:你給我記住......................

DIE
,this_object());
    ::die(1);
    }   

