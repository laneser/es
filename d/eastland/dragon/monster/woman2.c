#include "../../layuter.h"

inherit MONSTER;

void create()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(1);
        set_name( "Six Poul", "六婆" );
        add ("id", ({ "draconian", "woman","poul" }) );
        set_short( "六婆");
        set("unit","位");
        set("alignment",-100);
        set("weight",400);
        set("wealth/silver",10);
        set_long(
           "六婆是龍人族中有名的長舌婦，城裡大大小小的閒事你問她準沒錯。\n"
        );
        set_perm_stat("int", 2);
        set_perm_stat("dex", 2);
        set_perm_stat("kar",2);
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        set_c_verbs(({"%s用她的手掌打向%s", "%s用她的舌頭向%s舔去"}));
        set("chat_chance",10);
        set("chat_output",({
          "六婆說：阿牛聽說要娶老婆了。\n",
          "六婆說：聽說祭師藏有一個重要的卷軸。\n",
          "六婆說：龍人戰士們最近聽說要出征了。\n",
          "六婆說：聽說要找到那棵樹，要有耐心且仔細的尋找。\n"
          }));
}
