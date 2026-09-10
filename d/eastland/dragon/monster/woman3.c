
#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(1);
        set_name( "aunt cheng", "張大嬸" );
        add ("id", ({ "draconian", "cheng","aunt" }) );
        set_short( "張大嬸");
        set("unit","位");
        set("alignment",-100);
        set("weight",400);
        set("wealth/silver",10);
        set_long(
           "張大嬸最喜歡道人長短，而且喜歡散佈謠言。\n"
        );
        set_perm_stat("int", 2);
        set_perm_stat("dex", 2);
        set_perm_stat("kar",2);
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        set_c_verbs(({"%s用她的手掌打向%s,%s用她的舌頭向%s舔去"}));
        set("chat_chance",5);
        set("chat_output",({
          "張大嬸說：阿牛聽說要取老婆了。\n",
          "張大嬸說：烏家的小兒子聽說是白痴。\n",
          "張大嬸說： 聽說小龍女生了一個女娃。\n",
          "張大嬸說：聽說鄭大戶藏有一瓶陳年好酒。\n",
          "張大嬸說：聽說龍人工匠是一個不出世的奇人，任何物品他都造的出來。\n" 
          }));
}
