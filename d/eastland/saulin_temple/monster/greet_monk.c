#include "saulin_monka.c"

void create()
{
        ::create();
        set_level(5);
        set_name( "greeting monk", "知客僧" );
        add ("id", ({ "monk" }) );
        set_short("知客僧");
        set("unit","位");
        set_long(@C_LONG
他是一位年輕的和尚，因為沒有修練武功和參禪毅力和悟心，但卻有一張能言
善道的嘴，所以只能負責接待來訪少林的香客和武林人物。
C_LONG
        );
        set("alignment",100);
        set("wealth/silver",10);
        set_perm_stat("str", 9);
        set_perm_stat("dex", 9);
        set_natural_weapon(8, 5, 9);
        set_natural_armor(20, 16);
        set("max_hp", 200);
        set("hit_points", 200);
        set("special_defense", ([ "all" : 5, ]) );
        set("aim_difficulty", ([ "critical" : 15, "vascular" : 30, ]) );
        set_skill("dodge",40);
//		set("defense_type","dodge");
        set_skill("unarmed",70);
        set("gender", "male");
        set("race", "human");
        set_c_verbs(({ "%s一指戳向%s", "%s一腳踢向%s", "%s揮拳打向%s" }));
        set_c_limbs(({ "身體", "頭部", "腳部", "手臂" }));       
#include <replace_mob.h>
}
