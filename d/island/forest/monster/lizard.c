#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(14);
    set_name("Huge Lizard","大蜥蜴");
    add("id",({"lizard"}) );
    set_short("大蜥蜴");
    set_long(@LONG
一隻巨大的蜥蜴，慵懶的趴在你的面前，口中不斷的吐信，彷佛在探查你的來意
似的。嘴邊遺留著尚未嚼碎的白骨，天啊，這是隻肉食性的大爬蟲，你可得小心羅
，以防它趁人不備時偷襲。
LONG
            );
    set("unit","只");
    set("alignment",-2000);
    set("weight",2000);
    set("max_hp",500);
    set("hit_points",500);
    set_natural_weapon(20,21,30);
    set_natural_armor(60,35);
    set("unbleed",1);
    set_skill("dodge",80);
    set_skill("parry",60);
    set_skill("unarmed",50);
    set_perm_stat("str",25);
    set_perm_stat("dex",23);
    set_c_verbs( ({"%s的舌頭卷向%s","%s用利爪刺向%s","%s的尾巴掃向%s"}) );
    set_c_limbs( ({"尾巴","利爪","頸部","額頭","舌頭"}) );
    set("alt_corpse",TOBJ"shield2");
    set("death_msg","%s\n");
    set("c_death_msg",
    "%s和緩的伏在你面前，恭敬的稱呼一聲：主人！一陣白煙之後，眼前只留下一面盾!\n");
}
