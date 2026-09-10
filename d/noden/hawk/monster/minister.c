#include "../hawk.h"
inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "Hell Minister", "冥界修道士" );
        set("id",({"minister","hell minister","hell"}));
        set_short( "冥界修道士" );
        set_long(@LONG
冥界修道士是為維持冥界的和平，在地獄中接受黑帝斯的訓練的法
師，在地獄嚴苛的訓練之下，他們不但精通數種威力相當大的法術，同
時更具有遠比法師強壯的肉體，手中的幽冥權杖，則是冥帝所賜，做為
修道士們的信物
LONG
        );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "str", 20 );
        set_perm_stat( "int", 25 );
        set_skill( "dodge" , 100 );
        set_skill( "parry" , 100 );
        set_skill( "unarmed" , 50 );
        set ("max_hp", 700 );
        set ("hit_points", 700 );
        set_natural_weapon( 35 , 15 , 30 );
        set_natural_armor( 40 , 30 );
        set( "aim_difficulty",
        ([ "critical":30,"weakest":70,"ganglion":10 ]) );
        set ("special_defense",
        ([ "monk": 20, "scholar": 20, "evil": 100 , "divine": -20,
                "fire": 80, "electric":60, "cold":60, "energy": 30]) );
        set( "race", "human" );
        set( "gender", "male" );
        set( "pursuing", 1);
        set( "killer", 1);
	wield_weapon(WEAPON"wand");
        equip_armor(ARMOR"cloth03.c");
        equip_armor(ARMOR"god_4.c");
        set( "tactic_func","my_tactic");

}

int my_tactic()
{
        int dam;
        object victim;
        if (!victim = query_attacker()) return 0;
        if ( random(25) < 21) return 0;

        tell_object(victim,@C_LONG

修道士對你陰惻惻的一笑，舉起手中的權杖，喃喃的唸了幾句咒語

突然你感到黑帝斯正冷冷的看著你，雙手一揮，一陣黑霧將你團團圍住，
這股似邪非邪，似善非善，忽冷忽熱的感覺讓你受到了前所未有的傷害

C_LONG
);
        tell_room(environment(victim),@LONG

修道士大喊：尊貴崇高的冥帝，我的主人....協助我打敗我的敵人吧！

只見上空突然籠罩著一大片烏雲，黑帝斯的聲音幽幽的從四面八方傳了過來：
誰膽敢與我的使者為敵....給你五秒鐘 Quit 不然....你會後悔的

你感到一股無比強烈的殺氣肆虐在整個戰場上，修道士的敵人受到了超乎想像
的傷害。

LONG
);
        dam = 5 + random(5);
        victim->receive_special_damage( "evil", dam);
        victim->receive_special_damage( "divine", dam);
        victim->receive_special_damage( "fire", dam);
        victim->receive_special_damage( "cold", dam);
        victim->receive_special_damage( "electric", dam);
        victim->receive_special_damage( "energy", dam);
        victim->receive_special_damage( "acid", dam);
        victim->receive_damage(dam);
        return 1;
}

void die()
{
        object killer;
        killer = query("last_attacker");
        killer->set_temp("smore_armor/minister",1);
        ::die();
        return;
}
