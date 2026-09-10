#include "../iigima.h"
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(16);
        set_name("eight tail snake","八歧大蛇 ");
        add( "id", ({ "snake" }) );
        set_short("snake","八歧大蛇 ");
        set_long(@C_LONG
天吶？！這是個什麼樣的怪物？一條有八條尾巴的巨蛇，你幾乎不相信，這會是
存在於這個世界上的生物！火紅的眼睛閃爍著燃燒異樣的光芒，一身黑褐色的鱗
甲，尤其是那八條蠕動的尾巴，不時地發出吱吱的聲音，更是看了膽顫心驚！！
C_LONG
        );
        set( "unit", "條" );
        set( "alignment", -1000 );
        set_perm_stat( "dex", 24 );
        set_perm_stat( "str", 22 );
        set("max_hp",600);
        set("hit_points",600);
        set( "weight", 3000 );
        set( "special_defense", ([ "all":20,"evil":80,"fire":50,"none":5]) );
        set( "aim_difficulty", ([
            "ganglion" :10, "weakest" :20, "vascular" :10 ]) );
        set_natural_armor( 75, 20 );
        set( "natural_weapon_class1", 29 );
        set( "natural_min_damage1", 35 );
        set( "natural_max_damage1", 45 );
        set_skill( "dodge",90 );
        set_c_limbs( ({ "頭部", "龐大身軀", "尾巴" }) );
        set_c_verbs( ({
                       "%s昂頭張開大嘴，朝%s咬過去！",
                       "%s甩動它的頭，向%s撞了過去！",
              }));
        set( "chat_chance", 10 );
        set( "chat_output", ({
                "八岐大蛇發出吱吱的叫聲！\n",
                "八岐大蛇用血紅的眼睛瞪著你！\n",
                "八歧大蛇圍繞在陣陣的黃色煙霧當中...\n",
                        }));
        set("tactic_func","special_attack");
        set( "killer", 1 );
}

int special_attack()
{
  object *victim;
  int i;

  if (!(victim=query_attackers())) return 0;

  if (random(10)<2) return 0;

  i=sizeof(victim);

  if (random(22)<7) {
    tell_room(environment(this_object()),
"八岐大蛇發出刺耳的尖叫，瘋狂甩動八條尾巴，形成一股漩渦氣流，橫掃千軍\n"
    ,this_object());
    while(i--)
      victim[i]->receive_damage(random(10)+10);
    return 1;
  }
  if (random(25)<7) {
    tell_room(environment(this_object()),
"八岐大蛇張開血盆大口，突然激射出千萬利牙刺向所有人！\n"
    ,this_object());
    while(i--)
      victim[i]->receive_damage(random(10)+15);
    return 1;
  }

  if (random(33)<7) {
    tell_room(environment(this_object()),
"八岐大蛇的火紅雙眼怒視四方，八條尾巴捲起有如死神降臨人間，狂暴衝擊攻向在場
所有敵人！！\n"
    ,this_object());
    while(i--)
      victim[i]->receive_damage(random(10)+20);
    return 1;
  }
}
void announce( string c_msg )
{
        object *usr;
        int i;
        usr = users();
        for( i=0; i<sizeof(usr); i++ ) {
                if( !environment(usr[i]) ) continue;
                tell_object( usr[i], c_msg);
        }
}
void die()
{
        object obj;
        obj = query("last_attacker");
        if (obj->query_temp("drow_certi") != 3)
        {
	tell_room(environment(obj),
		"大蛇狂吼一聲，倒在地上，死了。",this_object() );
	::die(1);
        }

        announce(
        "諾頓皇宮的地底下不斷傳來陣陣的尖叫聲....\n"
        "整個諾頓皇城不斷的震動著!!\n");
        if( (int)obj->query_quest_level("drow_disaster") < 1 )
        {
        obj->finish_quest("drow_disaster",1);
        tell_object( obj, "你已經完成這個任務, 你得到10000點經驗值。\n" );
        obj->gain_experience(10000);
        }
        ::die(1);
}

