#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(15);
    set_name("Huge Turtle","巨龜");
    add("id",({"turtle"}) );
    set_short("巨龜");
    set_long(@LONG
這是一隻巨大的老海龜，充滿磨痕的龜殼及滿布皺紋的皮膚，在在顯示了它所走過
的歲月是多麼的悠久；對於你突然的出現，它似乎顯得有點驚訝，或許此處難得有其
他生物來訪吧！千萬不要驚擾它哦，一旦讓它生氣起來，可不是哄哄它就沒事的哦！
LONG
            );
    set("unit","只");
    set("alignment",-1500);
    set("weight",2000);
    set("likefish",1);
    set_perm_stat("str",25);
    set("hit_points",1000);
    set("max_hp",1000);
    set_natural_weapon(40,20,30);
    set_natural_armor(50,40);
    set("unbleed",1);
    set_skill("parry",80);
    set_c_verbs( ({"%s的頭頂向%s","%s的巨掌推向%s","%s的尾巴掃向%s"}) );
    set_c_limbs( ({"尾巴","利爪","頸部","額頭"}) );
    set("alt_corpse",TOBJ"boot1");
    set("death_msg","%s\n");
    set("c_death_msg","%s和緩的伏在你面前，恭敬的稱呼一聲：主人！接著化成一雙鞋子!\n");
    }