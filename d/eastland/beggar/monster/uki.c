#include "/d/eastland/beggar/dony.h"

#define MAX_HP(x)   (int)x->query("max_hp")
#define HP(x)       (int)x->query("hit_points")
#define NAME(x)     (string)x->query("name") 
#define BANDAGED(x)  x->query_temp("bandaged")
        
inherit MONSTER;

void create()
{
    ::create();
    set_level(17);
    set_name( "Doctor Uki", "小雪子" );
    add( "id",({"doctor","uki"}) );
    set_short( "一代神醫 小雪子");
    set_long(@LONG
小雪子看起約莫二十四、五歲的年紀,亭亭玉立,身材苗窕,顧盼間頗有勾魂奪魄之
態。同時,她也是這裡唯一的行醫者,雖然她年紀不大,頗得醫仙的真傳,所以,凡有
受傷或者遭逢疾病的, 都會來向她請教 ( help )。漸漸地,她的名氣傳了開來,不
少年輕公子哥兒都來追求她,想一親芳澤,可是落花無情,誰也不知道她心裡在想些
什麼。 
LONG
            );
    set("unit","位");
    set("race","human");      
    set("class","healer");
    set("age",18);
    set("gender","female" );
    set("alignment",1000);
    set("weight",600);
    set("wealth/gold",2);
    set_temp("be_joke",100);
    set_perm_stat("str",19);
    set_perm_stat("dex",26);
    set_perm_stat("kar",30);
    set_perm_stat("int",28);
    set_perm_stat("pie",23);
    set("hit_points",550);
    set("max_hp",550);
    set("max_fp",300);
    set_natural_armor(20,44);
    set_natural_weapon(21,0,0);
    set_skill("dagger",80);
    set_skill( "bandage",90);
    set_skill("anatomlogy",100);
    set_skill("dodge",75);
    set_skill("parry",70);
    set("stun_difficulty",50);                                              
    set("special_defense", ([ "all": 40,"none":30,"monk":30,"scholar":30]) );
    set("aim_difficulty",
    (["critical":50,"vascular":70,"ganglion":70,"weakest":30]) );
    set("stun_difficulty",90);
    wield_weapon(DWEAPON"needle");
    equip_armor(DARMOR"uki_cloth");
    equip_armor(DARMOR"uki_amulet");
    set( "inquiry", ([
              "help":"@@ask_help",
           "bandage":"@@ask_bandage",
               "hau":"@@ask_hau",
               "war":"@@ask_war" 
    ]) );                       
    set( "tactic_func", "my_tactic" );
}        

void init()
{ 
  ::init();
  add_action("do_angry","slap");
  add_action("do_angry","kick");
  add_action("do_angry","kiss");
  add_action("do_angry","flog");
  add_action("do_angry","hold");
  add_action("do_angry","lkiss");
  add_action("do_angry","smirk");
  add_action("do_angry","excite");
  add_action("do_angry","puke");
  add_action("do_angry","snort");
  add_action("do_angry","bite");
  add_action("do_angry","lick");
  add_action("do_angry","bark");
  add_action("do_angry","fart");
  add_action("do_angry","spit");
}

void do_angry(string arg)
{
   call_out("do_kick",4,arg);
}

void do_kick(string arg)
{
    if (arg=="uki"){
       tell_object( this_player(),
          "\n小雪子憤怨地向你說道:你這無禮的小賊去死吧 !!\n\n");
       tell_room( environment(this_object()),
          "\n小雪子似乎對"+this_player()->query("c_name")+
          "很不爽並對他採取攻擊!!\n\n",this_player());
       this_object()->kill_ob(this_player());
       this_player()->block_attack(6);
       this_player()->set_temp("msg_stop_attack","(  你因為太無禮而被攔住動彈不得 !!  )\n");
       return ;
    }
}
void ask_help( object asker )
{
    tell_object( asker ,
         "小雪子說道:哦,你要求幫助?\n"
         "小雪子語氣停頓並且深深地嘆了一口氣 ...\n"   
         "小雪子繼續說道:如果先師還在,那就可以幫你更多,可惜.....\n"
         "小雪子說道:幾年前幫中發生內亂,我師父不幸戰死,只留下一門包紮技能,\n"
         "           如果你能給我一些繃帶的話...............\n");
}

void ask_bandage( object asker )
{
     object ob1;
     
     if ( !asker->debit("gold", 6) ) {
        tell_object( asker, 
          "小雪子說道:我幫你包紮總需要拿點工本費吧!\n");
        return ;     
     }
     if ( asker==query_attacker() ) {
        tell_object( asker , 
          "小雪子怒道:哼,你別笨得可以了,我怎麼可能幫敵人包紮咩?\n");
        return ;
     }
     if( !present( "bandage",this_object() ) ) {
        tell_object( asker , "小雪子說道:唉,我身上沒有任何繃帶可以幫你。\n");
        return ;
     }       
     if ( HP(asker)==MAX_HP(asker) ) {
        command( "look "+NAME(asker) );
        tell_object( asker , "小雪子說道:咦,你好好的嗎。\n");
        return ;     
     }
     if ( BANDAGED(asker) ) {
        command( "look "+NAME(asker) );
        tell_object( asker , "小雪子說道:哦,你似乎被包紮過了...\n");
        return ;    
     }
     command( "look "+NAME(asker) );
     command( "bandage "+NAME(asker) );
     command( "smile "+NAME(asker) );
     tell_object( asker, 
        "你很感激地想親 ( kiss ) 小雪子一下做為報答,但是想想又覺得不妥。\n");
     return ;                 
}

void ask_hau( object asker )
{
    if ( asker->query_temp("keeper_finish1") ) {
       tell_object( asker ,
          "小雪子說道:哦,你問帳房霍先生的內人?\n"
          "你向小雪子報告所發生的事。\n"
          "小雪子思考了一會兒。\n" 
              );
       asker->set_temp("uki_asked",1);
       call_out("recover1",10,asker);
    } else 
       tell_object( asker,
          "小雪子說道:我不知道。\n");
}

void recover1( object obj)
{
    tell_object( obj ,
       "小雪子說道:唉,我也不知道為什麼會這樣,我只知道熊蛇丸可以起死回生。\n"
       "           嗯,你去請教 祠堂 老院長 吧,他活得久可能知道些什麼。\n"         
       "\n你心裡罵小雪子是個大庸醫。\n"
                );
}
void ask_war()
{
write(@C_LONG
小雪子說道:記得在我很小的時候,這裡發生了一件慘事,唉,我師父就在那裡時候陣亡。
           唉唉.......
小雪子似乎不太想說。           
C_LONG
    );
}
int my_tactic()
{
     object victim;
     int select;     
     
     if (!(victim= query_attacker())) return 0;
     if ( victim->query("conditions/herb_apply") ) {
        tell_object(victim,
          "小雪子狂笑道:哈哈哈哈哈,在我面前竟敢塗藥藥?別傻了!!!\n");
        victim->delete("conditions/herb_apply"); 
     }      
     select=random(10);
     if ( select > 4 ) set("aiming_loc","critical");
     else if ( select > 1 ) set("aiming_loc","weakest");
     else if ( select > 0 ) {
        if ( victim->query("conditions/bleeding") ) set("aiming_loc","weakest");
        else set("aiming_loc","vascular");
     }
     return 0;          
}                  