#include "saulin_monka.c"

void create()
{
        ::create();
        set_level(4);
        set_name( "little monk", "小沙彌" );
        add ("id",({ "monk"}));
        set_short("小沙彌");
        set("unit","位");
        set_long(@C_LONG
他是一位很可愛的小孩，頂著一顆小小的光頭，一副什麼都不懂的樣子
小沙彌是從小就被送到少林的孩子，很多都是孤兒或者棄嬰。
C_LONG
        );
        set("alignment",150);
        set("wealth/silver",15);
        set_perm_stat("str",7);
        set_perm_stat("dex",7);
        set_perm_stat("kar",6); 
        set_natural_weapon( 6, 4, 6 );
        set_natural_armor( 20, 8 );
        set_skill("dodge",25);
        set("gender", "male");
        set("race", "human");
        set_c_verbs(({ "%s用雙手向%s亂抓一通", "%s用短腳向%s亂踢七八腿",
                       "%s用光頭向%s大力的撞去",
        }));
        set_c_limbs(({ "身體", "光頭", "小腳", "小手", "屁股", }));
#include <replace_mob.h>
}
