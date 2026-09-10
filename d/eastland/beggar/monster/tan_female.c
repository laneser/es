#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "moon female", "陰婆婆" );
	add("id",({"moon","female"}) );
        set_short( "大別山碧雲洞 陰婆婆" );
	set_long(@C_LONG
陰婆婆約莫五、六十歲年紀,身材牛馬高大,白髮如銀,滿臉皺紋和陽公公短小的身
材來比,相□成趣。 她自二十年前就與陽公公穩居在大別山碧雲洞一直未涉世,最
近因丐幫的邀請特地趕來參加丐幫『祭祖大典』盛會。
C_LONG
	);
	set( "gender", "female" );
	set( "race", "human" );
	set( "alignment", 30 );
	set_natural_armor( 40 , 40 );
	set_natural_weapon( 50 , 25 , 33);
	set("max_hp",420);
	set("hit_points",420);
	set_perm_stat( "str", 26 );
	set_perm_stat( "dex",22 );
	set_perm_stat( "int",23 );
	set_skill( "parry",35 );
	set_skill( "dodge",60 );
	set( "wealth/silver",100);
	set( "special_defense", ([ "all": 35,"none":40 ]) );
	set( "aim_difficulty",(["critical":60,"vascular":40,"weakest":40]) );
	set("couple",1);
        set_c_verbs( ({ "%s使出『打咀巴』第一武, 欺向%s。",
                        "%s橫身而來『打咀巴』第二招, 雙手向%s打去。",
                        "%s大叫一聲,『打咀巴』最強一式啪啪啪三個巴掌打向%s。"
                      }) ); 
        set( "chat_chance", 22 );
        set( "att_chat_output", ({
                "陰婆婆怒道:無知小賊,我陰婆婆豈是這麼好欺負的!! \n"
        }) );
                                         
        equip_armor(DARMOR"tan_ring");
        set( "tactic_func", "my_attack" );
} 

int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
        return 0;
}

int my_attack()
{ 
    object victim, *couples;
    int i;
  
    victim = query_attacker();
    if( !victim ) return 0;

    couples = filter_array( all_inventory(environment(this_object())),
        "can_help", this_object() );
    for( i=0; i<sizeof(couples); i++ ) {
         tell_room( environment(this_object()), couples[i]->query("c_name")+
            "說道:想找我們過招,你們配嗎?\n",couples[i]);
            couples[i]->kill_ob(victim);
    }
                                                      
    if  ( random(14)>2 )  return 0;
    else{
       tell_room( environment(this_object()),
           "陰婆婆手起落賞"+victim->query("c_name")+"一個老大括子!!\n",victim);
       tell_object( victim,"陰婆婆手起落賞你一個老大括子!\n");
       victim->receive_damage(12);
       return 1;
   }      
}


