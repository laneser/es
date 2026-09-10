#include "../forest.h"

void create(object ob)
{
        if ( !ob ) return ;
        ob->set_level(8);
        ob->set_name( "gorilla", "人猿" );
        ob->set_short("人猿");
        ob->set("unit","只");
        ob->set_long(@C_LONG
在你面前的是一隻人型的動物，有健全的雙手雙腳，但是全身毛茸茸的。
它似乎較其他的動物聰明一些，靈慧的模樣令人不捨得殺它。
C_LONG
        );
        ob->set_perm_stat( "str", 12 );
        ob->set_perm_stat( "dex", 18 );
        ob->set_perm_stat( "int", 18 );
        ob->set_perm_stat( "kar", 15);
        ob->set("wimpy",50);
        ob->set_skill("dodge",100);
        ob->set("max_hp", 300);
        ob->set("hit_points", 300);
        ob->set("special_defense", ([ "all":40, "none":20, ]) );
        ob->set("aim_difficulty",
        	([ "critical":45, "vascular":80, "weakest":30, "ganglion":60 ]) );
        
        ob->set( "alignment",500 );
        ob->set_natural_weapon(17,12,20);
        ob->set_natural_armor(50,30);
        ob->set_c_verbs(({"%s用它的拳頭向%s攻擊","%s用它的腳向%s踢去",
                      "%s用它的頭向%s猛烈地撞去"}));
        ob->set_c_limbs(({"身體","腳部","頭部","手部"}));
}
