#include "mudlib.h"

void create(object ob)
{
        if ( !ob ) return ;
        ob->set_level(12);
        ob->set_name( "cheetah", "印度豹 " );
        ob->set_short( "印度豹 " );
        ob->set_long(@C_LONG
這是一只有著漂亮毛皮，修長身驅的動物。它的動作非常地快，
是一種具有危險性的肉食動物。
C_LONG
        );
        ob->set("unit","頭");
        ob->set_perm_stat( "str", 18 );
        ob->set_perm_stat( "dex", 20 );
        ob->set_perm_stat( "int", 10 );
        ob->set_perm_stat( "kar", 18 );
        ob->set_skill( "dodge", 80);
        ob->set("max_hp", 350);
        ob->set("hit_points", 350);
        ob->set("special_defense", ([ "all":30, "none":15, "fire":3 ]) );
        ob->set("aim_difficulty",
            ([ "weakest":40, "ganglion":30 ]) );
        
        ob->set( "killer", 1);
        ob->set( "c_kill_msg", "突然間，印度豹從樹上向你猛撲了過來 !!!!!" );
        ob->set( "alignment", -400 );
        ob->set_natural_weapon(35,13,23);
        ob->set_natural_armor(63,30);

        ob->set_c_verbs( ({ "%s用它的利爪向%s抓去", "%s迅速地撲向%s" }) );
        ob->set_c_limbs( ({ "頭部", "身體", "腳部"}) );
}
