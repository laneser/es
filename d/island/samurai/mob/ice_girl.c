#include "mudlib.h"

inherit MONSTER;

void create()
{
        
        ::create();
        set_level(19);
        set_name("ice_girl","冰女 雪菜");
        add ("id", ({ "girl", "ice","lulu" }) );
        set_short("ice_girl", "冰女 雪菜");
        set_long(
    "她是由冰之國溜出來的冰女,她正在尋找她的兄長飛影,你可別\n"
    "看她是個弱女子就欺負她,那你可能就要找黑無常聊天了!!\n"
       );

        set("alignment",-1000);
        set( "gender", "female" );
        set( "race", "daemon" );
        set( "unit", "個" );
        set( "forgetful", 1 );
        set_perm_stat( "str", 25 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "pie", 20 );
        set ( "hit_potion" ,1000);
        set ( "wealth" , ([ "silver": 2000 ]) );
        set_natural_weapon(35,10,20);
        set_natural_armor(40,40);
        set ("exp reward",24000);
        set ("chat_chance",15);
        set ("chat_output", ({
             "the girl say:do u see my brother?\n",
             "雪菜微笑著說:你知道我哥哥飛影的下落嗎? \n"
            }) );
        set("special_defense",(["all":50,"none":40]) );
        set("aim_difficulty",(["critical":5,"weakest":100,"vascular":100]) );
        set_c_verbs( ({"%s左手一個巴掌甩向%s","%s一招″升龍拳″擊向%s",
                       "%s一記″撩陰腿″踢向%s"}) );
        set ("weight", 400);
        set_skill("dodge",100);
        set_skill("parry",100);
        set( "tactic_func", "att_gonfus");
}
int att_gonfus()
{
    object victim;
    int dam;
    
    if( !(victim = query_attacker())  || (random(20)>2) ) return 0;
       tell_room( environment(this_object()), ({"\n",
       "\n\n雪菜雙手一抓,一口氣把"+victim->query("c_name")+"打了十幾個巴掌\n\n"
        }) );
      dam= 40 + random(30);  
      victim->receive_special_damage("evil", dam );
      return 1;
    }
   
  

