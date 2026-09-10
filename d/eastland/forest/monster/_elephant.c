#include "../forest.h"

void create(object ob)
{
        if ( !ob ) return ;
        ob->set_level(5);
        ob->set_name( "elephant", "大象" );
        ob->set_short("大象");
        ob->set("unit","頭");
        ob->set_long(@C_LONG
你看見一隻巨大的動物，有著長長的鼻子、巨大的耳朵、與兩根白色的長牙，
此時它正在森林中悠閒的漫步著。
C_LONG
        );
        ob->set_perm_stat("str", 8);
        ob->set_perm_stat("dex", 3);
        ob->set_natural_weapon(6,6,12);
        ob->set_natural_armor(25,0);
        ob->set_c_verbs(({"%s用它的長牙向%s攻擊","%s用它的長鼻甩向%s"}));
        ob->set_c_limbs(({"鼻子","身體","耳朵","腳部","頭部"}));
}
