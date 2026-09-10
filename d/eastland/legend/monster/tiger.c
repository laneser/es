#include <mudlib.h>

inherit MONSTER;
void create()
{
        ::create();
        set_level(14);
        set_name( "tiger", "老虎" );
        set_short( "老虎" );
        set_long(@C_LONG
這隻動物的外型有點像貓的，但身軀卻大很多。銳利的爪子和獠牙，是它獵食的主
要工具。是一種非常危險的肉食性動物。
C_LONG
        );
        set("unit","只");
        set_perm_stat( "str", 18 );
        set_perm_stat( "dex", 20 ); 
        set_perm_stat( "int", 12 );
        set_perm_stat( "kar", 18 );
        set_skill( "dodge", 90);
        set("max_hp", 450);
        set("hit_points",450);
        set("special_defense", ([ "all":25, "none":10,"fire":5 ]) );
        set("aim_difficulty",
                ([ "vascular":10, "weakest":20 ]) );
        set( "killer", 1);
        set( "c_killer_msg", "突然間，你看到老虎如餓虎撲羊般地向你急撲了過來!!!");
        set( "alignment", -500 );
        set_natural_weapon(40,17,27);
        set_natural_armor(70,1);
        set_c_verbs( ({ "%s兇猛地向%s一口咬去", "%s迅速地撲向%s",
                        "%s用它的利爪向%s用力地抓去"  }) );
        set_c_limbs( ({ "頭部", "身體", "腳部"}) );
}
