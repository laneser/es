#include "mercury.h"
inherit MMOB+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Ninja Calford", "忍者 加爾福特" );
	add( "id", ({ "ninja","calford" }) );
	set_short( "Ninja Calford", "忍者 加爾福特" );
	set_long(@AAA
你眼前是一位年輕的忍者，有著一頭金色的短髮和深藍色的眼睛，年
紀約只有十八．九歲而已，雖然年輕但卻是一個相當厲害的忍者喔！
AAA
 );
	set( "unit", "位" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 27 );
        set_perm_stat( "dex", 27 );
        set_perm_stat( "kar", 20 );
        set_perm_stat( "pie", 28 );    
        set( "max_hp",550 );
        set( "hit_points",550 );
 	set_natural_armor( 55,25 );
	set( "natural_weapon_class1", 25 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 35 ); 
        set( "special_defense",([ "all":25,"none":25 ])); 
        set( "aim_difficulty",([ "critical":80,"weakest":20,"ganglion":50,
                                 "vascular":35 ]));
        set( "stun_difficulty/ma",15);  
	set( "alignment", 1000 );
	set_c_limbs( ({ "頭部", "身體", "手腕", "咽喉" }) );
        set_skill( "parry",100 );
        set_skill( "dagger",100 );
        set_skill( "dodge",100);
        set( "wealth" , ([ "gold": 100 ]) );
        set( "tactic_func", "att_gonfus");
        set( "weight", 400 );
        wield_weapon(MOBJ"ninja_dagger");    
        equip_armor(MOBJ"ninja_vest");
        equip_armor(MOBJ"ninja_gloves");
        equip_armor(MOBJ"red_scarf");
        equip_armor(MOBJ"ninja_boots"); 
        set("moving",1);
        set("speed",45);
        set("patrol",({"south","north","east","west"}));
        set("inquiry",([
            "nakoruru":"啊!你是說娜考璐璐呀!真的是好久沒和她見面了,但是\n"
                       "我又不能離開這,而他的生日禮物 (present)我是準備好了,不知道你可不可\n"
                       "以幫我送一下",
            "present":"@@ask_present"
               ]));
}
int ask_present(object player)
{            
write(@AAA
加爾福特說道:東西我放在橘右京那裡,你就跟他說(o_i_la_shi)這個密碼
             他就會把禮物交給你了
AAA
);
player->set_temp("calford",1);
return 1;
}




int att_gonfus()
{
     object victim;
     int dam1,dam2,n;
     
     if( !(victim = query_attacker()) || (random(20)>4) ) return 0;
     else {
     switch (n=random(2))
{ case 0:
    {
     tell_room(environment(this_object()),
     "\n\n加爾福特突然衝到"+victim->query("c_name")+"面前，把他舉起來\n"+
     "\n加爾福特以一個忍法飛空摔把"+victim->query("c_name")+"狠狠地在地上摔出一個大洞\n\n"
      );
      dam1 = 15 + random(25);
      victim->receive_special_damage("electric", dam1 );
      report(this_object(),victim);
      return 1;
      }
  case 1:
     { 
       tell_room(environment(this_object()),
       "\n加爾福特對準"+victim->query("c_name")+"射出兩把的手裡劍\n"+
       "\n這兩把手裡劍在擊中"+victim->query("c_name")+"時．突然放出極大的閃電\n\n"
       );
       dam2 = 15 + random(15);
       victim->receive_special_damage("electric",dam2);
       report(this_object(),victim);
       return 1;
      }
}
}
}
