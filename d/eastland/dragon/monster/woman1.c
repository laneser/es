
#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(1);
        set_name( "Shan cool", "三姑" );
        add ("id", ({ "draconian", "shan", "cool", }) );
        set_short( " 三姑");
        set("unit","位");
        set("alignment",-100);
        set("weight",400);
        set("wealth/silver",10);
        set_long(
           "三姑是龍人族中最多嘴的人，城裡大大小小的閒事都是經由他傳播的。\n"
        );
        set_perm_stat("int", 2);
        set_perm_stat("dex", 2);
        set_perm_stat("kar",2);
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        set_c_verbs(({"%s用她的手掌打向%s", "%s用她的舌頭向%s舔去" }));
        set("chat_chance", 10);
        set("chat_output",({
          "三姑說：昨天隔壁李太太走路跌了一跤還摔斷的右腿，真是太笨了。\n",
          "三姑說：最近城南森林出現的一棵神秘怪樹，居然會移動位置，聽曾經見過它的人說那是棵高大強壯的樹。\n",
          "三姑說：吳太太養的豬最近生了一大窩小豬。\n"
        }));
}
