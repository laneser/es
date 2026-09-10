#include "../forest.h"

void create(object ob)
{
        if ( !ob ) return ;
        ob->set_level(14);
        ob->set_name( "tiger", "老虎" );
        ob->set_short( "老虎" );
        ob->set_long(@C_LONG
這隻動物的外型有點像貓的，但身軀卻大很多。銳利的爪子和獠牙，
是它獵食的主要工具。是一種非常危險的肉食性動物。
C_LONG
        );
        ob->set("unit","只");
        ob->set_perm_stat( "str", 18 );
        ob->set_perm_stat( "dex", 20 ); 
        ob->set_perm_stat( "int", 12 );
        ob->set_perm_stat( "kar", 18 );
        ob->set_skill( "dodge", 90);
        ob->set("max_hp", 450);
        ob->set("hit_points",450);
        ob->set("special_defense", ([ "all":25, "none":10,"fire":5 ]) );
        ob->set("aim_difficulty",
                ([ "vascular":10, "weakest":20 ]) );
        
        ob->set( "killer", 1);
        ob->set( "c_killer_msg", "突然間，你看到老虎如餓虎撲羊般地向你急撲了過來!!!");
        ob->set( "pursuing",1);
        ob->set( "alignment", -500 );
        ob->set_natural_weapon(40,17,27);
        ob->set_natural_armor(73,28);

        ob->set_c_verbs( ({ "%s兇猛地向%s一口咬去", "%s迅速地撲向%s",
                        "%s用它的利爪向%s用力地抓去"  }) );
        ob->set_c_limbs( ({ "頭部", "身體", "腳部"}) );
}
