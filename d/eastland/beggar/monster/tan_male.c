#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "sun male", "陽公公" );
	add("id",({"sun","male"}) );
        set_short( "大別山碧雲洞 陽公公" );
	set_long(@C_LONG
陽公公約莫六、七十歲年紀,自二十年前看破世事就與陰婆婆穩居在大別山碧雲洞
一直未涉世,因丐幫的邀請特地趕來參加丐幫『祭祖大典』。近年來新得極北玄玉
和玉火蟾蜍, 合成了靈驗無比的傷藥 ( herb ), 或許你可以向他要要看是否他會
給你一些。
C_LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 50 );
	set_natural_armor( 40 , 40 );
	set_natural_weapon( 50 , 25 , 33);
	set("max_hp",460);
	set("hit_points",460);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex",20 );
	set_perm_stat( "int",25 );
	set_skill( "parry",30 );
	set_skill( "dodge",70 );
	set( "wealth/silver",1);
	set( "special_defense", ([ "all": 40,"none":40 ]) );
	set( "aim_difficulty",(["critical":100,"vascular":40,"weakest":40]) );
	set("couple",1);
        set_c_verbs( ({ "%s使出『捱打不還手』第一招, 隻手欺向%s。",
                        "%s虛晃一下『捱打不還手』第二招, 臉朝向%s準備被打。",
                        "%s吼叫一聲,『捱打不還手』最強一式急打自己臉頰然後向%s砍了過去。"
                      }) ); 
        set( "chat_chance", 15 );
        set( "att_chat_output", ({
                 "陽公公說道:來人啊,救命啊,欺負老弱婦孺～ \n"
        }) );
        equip_armor(DARMOR"tan_ring");
        set("inquiry", ([
             "herb":"@@ask_herb"
        ]) );
        set( "tactic_func", "my_attack" );
} 
void ask_herb(object asker)
{
write(@C_LONG
陽公公說道:本來我在一處極熱的地方捕獲到一隻玉火蟾蜍。但是,這幾天又失落了,
           你能幫我找回來嗎?
C_LONG
      );
}
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
       return 0;
}
int accept_item(object me,object item)
{
    string name;
    name=item->query("name");
    if ((name!="fire toad")&&(name!="box")){
        tell_object(me,this_object()->query("c_name")+
              "說道:你給我這個東西幹嘛啊?\n");
        item->move(me) ;
        return 1;
    }
    if (name=="fire toad"){
       tell_object(me,this_object()->query("c_name")+
              "感激地說道:謝謝你幫我找回來"+item->query("c_name")+
              "請你等一下,我做一下藥～～\n"); 
       item->remove();
       call_out("recover",2,me);      
       return 1;
    }  
    if ( item->query("charge_times")<1){
       tell_object(me,this_object()->query("c_name")+
            "說道:唉,你的小盒子太舊了～～\n");
       tell_object(me,this_object()->query("c_name")+
            "說著說著把你給他的小盒子拿丟掉!!\n");
       item->remove();
       return 1;    
    }
    if (me->query("wealth/silver")<1500){
       tell_object(me,this_object()->query("c_name")+
              "說道:想續杯,可以,請悽足一千五百大洋～～\n");
       command("give box to "+me->query("name"));
       return 1;
    }
    me->add("wealth/silver",-1500); 
    item->set("times",10);
    item->add("charge_times",-1);
    tell_object(me,this_object()->query("c_name")+
              "說道:好了,你的小盒子又裝著滿滿的藥～～\n"); 
    command("give box to "+me->query("name"));
    return 1;
}
void recover(object obj)
{
   object bonus;
   bonus=new(DITEM"box.c");
   bonus->move(this_object());
   tell_object(obj,this_object()->query("c_name")+
        "說道:嗯,我做的治傷靈藥太多了,我把它放在小盒子裡分你一些吧。\n");
   command("give box to "+obj->query("name"));
}
int my_attack()
{ 
    object victim,*env,*couples;
    int i;
    
    victim = query_attacker();
    if( !victim ) return 0;

    env=all_inventory(environment(this_object()));
    couples = filter_array( env,"can_help", this_object() );
    for( i=0; i<sizeof(couples); i++ ) {
        tell_room( environment(this_object()), couples[i]->query("c_name")+
           "說道:想找我們過招,你們配嗎?\n",couples[i]);
        couples[i]->kill_ob(victim);
    }

    if  ( random(12)>1 )  return 0;
    else{
       tell_room( environment(this_object()),
           "陽公公迅速地從懷中取出一隻小盒,打開盒子,伸指沾些藥膏塗在傷口處!\n");
       for ( i=0;i<sizeof(env);i++) 
          if ( env[i]->query("couple") )      
            env[i]->receive_healing(20);  
       return 1;
   }      
}


