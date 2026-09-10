#include <mudlib.h>

inherit MONSTER;

void create ()
{
       ::create();
       set_level(14);
       set_name( "ice toad", "冰蟾蜍");
       add ("id", ({ "toad" }) );
       set_short( "冰蟾蜍");
       set("unit","只");
       set_long(@LONG
    一隻只有指頭大小的蟾蜍。透明的身體外有一條條鮮紅色的細紋，看起來相當的
□麗。
LONG    );
       set_skill("dodge",100);
       set_natural_weapon(35,10,12);
       set_natural_armor(60,15);
       set_c_verbs(({
         "%s吐出它的舌頭向%s捲了過來",
         "%s向%s撲了過來",
         "%s高高的跳起然後撞向%s",
         "%s咕哇一聲怪叫，射出一股煙霧罩向%s",
         }));
       set_c_limbs(({"腹部","頭部","腿部"}));
}
