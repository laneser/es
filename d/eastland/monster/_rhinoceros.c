#include <mudlib.h>

void create(object ob)
{
		if ( ! ob ) return ;
        ob->set_level(14);
        ob->set_name( "rhinoceros", "犀牛" );
        ob->set_short("犀牛" );
        ob->set_long(@C_LONG
這隻動物看起來很呆呆的, 似乎沒什麼攻擊性....
咦, 不對, 它的角上沾滿了血跡, 恐怕有人喪命於他,
最好還是提高警覺!
C_LONG
        );
        ob->set("unit","只");
        ob->set_perm_stat( "str", 22 );
        ob->set_perm_stat( "dex", 15 ); 
        ob->set_perm_stat( "int", 12 );
        ob->set_skill( "dodge", 80);
        ob->set("max_hp", 600);
        ob->set("hit_points",600);
        ob->set("special_defense", ([ "all":25, "none":10,"fire":5 ]) );
        ob->set("aim_difficulty",
                ([ "vascular":10, "weakest":20 ]) );
        
        ob->set( "alignment", 200 );
        ob->set_natural_weapon(40,15,25);
        ob->set_natural_armor(40,30);
        ob->set_c_verbs( ({ "%s兇猛地向%s一口咬去",
                        "%s用它的角全力向%s頂過去"  }) );
        ob->set_c_limbs( ({ "頭部", "身體", "腳部"}) );
}
