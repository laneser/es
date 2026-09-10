#include "../forest.h"

void create(object ob)
{
		if ( !ob ) return ;
        ob->set_level(17);
        ob->set_name( "lion", "獅子" );
        ob->set_short( "獅子" );
        ob->set_long(@C_LONG
這是一隻臉上長滿鬃毛的動物，懶洋洋的樣子似乎沒有什麼危險性。
但是森林中的動物似乎都不敢靠近它，還是小心一點的好。
C_LONG
        );
        ob->set("unit","只");
        ob->set_perm_stat( "str", 23 );
        ob->set_perm_stat( "dex", 25 );
        ob->set_perm_stat( "int", 13 );
        ob->set_perm_stat( "kar", 20 );
        ob->set_skill( "dodge", 100 );
        ob->set("max_hp", 550);
        ob->set("hit_points", 550);
        ob->set("special_defense", ([ "all":50, "none":25,"fire":5 ]) );
        ob->set("aim_difficulty",
            ([ "vascular":10,"weakest":30 ]));
        
        ob->set( "aggressive", 1 );
        ob->set( "c_killer_msg","你突然發覺獅子正張開它的大口向你背後撲了過來....");
        ob->set( "alignment", -500 );
        ob->set_natural_weapon(50,22,30);
        ob->set_natural_armor(70,30);

        ob->set_c_verbs( ({ "%s張開它的大口，一口向%s咬去", "%s迅速地向%s撲去" }) );
        ob->set_c_limbs( ({ "頭部", "身體", "腳部" }) );
}
