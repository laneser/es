#include "../story.h"
inherit MONSTER;

void create()
{
    ::create();
    set_level(18);
    set_name( "swordman Eight-snow", "八門吹雪" );
    add ("id", ({ "swordman" }) );
    set_short( "劍客 八門吹雪");
    set_long(@LONG
八門吹雪看起來約莫四、五十歲年紀，留著一對八字鬍，兩頰鬢須過肩。他生得面
如冠玉、目若朗星，一副道貌岸然的樣子；行立間，飄飄然有如神仙貌；端坐時，
雙眉中隱隱透露著威嚴狀；此人似乎只應天上有之。八門吹雪正坐在礁石上，臉上
神情凝重，雙眉頻蹙，似乎在鑽研著什麼。
LONG
            );
    set("unit","位");
    set("race","human");      
    set("age",49);
    set("gender","male" );
    set("alignment",500);
    set("weight",1000);
    set("wealth/gold",80);
    set_perm_stat("str",28);
    set_perm_stat("dex",23);
    set_perm_stat("int",25);
    set("hit_points",800);
    set("max_hp",800);
    set("max_fp",300);
    set_temp("be_joke",2);
    set_natural_armor(80,24);
    set_natural_weapon(15,15,5);
    set_skill("longblade",90);
    set_skill("dodge",90);
    set_skill("parry",90);
    set("special_defense", ([ "all": 40,"none":30]) );
    set("aim_difficulty",
    (["critical":50,"vascular":30,"ganglion":30,"weakest":30,"scholar":20]) );
    set("stun_difficulty",50);
    wield_weapon(SWEA"sword1");
    equip_armor(SARM"ring1");
    equip_armor(SARM"amulet1");
    set( "tactic_func", "my_tactic" );
}        
int my_tactic()
{
     object victim,env;
     int select;     
     
     if (!(victim= query_attacker())) return 0;
     env=environment(this_object());
     switch (random(60)) {
     case 0..8 :
        victim->receive_damage(40+random(30));
        tell_room(env,
           "\n八門吹雪引起漫天海水，水助劍勢狠狠往敵人面門一戳！\n\n\n");
        return 1;
     case 9 :
        this_object()->receive_healing(60);
        tell_room(env,
           "八門吹雪手中的「咒符」發出一道藍光，瞬間，他的傷口癒合了！\n");
        return 1; 
     }
     return 0;          
}                  