#include <mudlib.h>

inherit MONSTER;
void die();
int calloutcheck = 0;
string laugh,*action =
     ({ "%s指著%s的ＸＸ笑得直不起腰來。\n",
        "%s在%s的四周跳來跳去，拿大鼎、翻跟斗。\n",
        "%s裝上一個紅紅的小丑鼻子，對著%s搖頭晃腦。\n",
        "%s一屁股坐在地上，指著%s哇啦哇啦的哭了起來。\n",
        "%s用泥巴亂塗%s的臉。\n" }) ;

void create()
{       
	::create();
	set_level(19);
	set_name( "Water Beast", "無支祈" );
	add( "id", ({ "beast","water beast"}) );
	set_short( "水怪 無支祈" );
	set_long(@C_LONG
這是一支善於應對言語的怪物, 形狀像猿猴, 額頭高, 鼻樑低, 白腦袋, 青身子,
牙齒雪亮, 眼睛閃爍出金光, 力量大過九隻象, 頸脖子伸出來有百尺長, 但他的
身軀卻伶俐輕便。
C_LONG
);
        set("killer",1);
	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "int", 30 );
	set_skill( "unarmed", 100);
	set_natural_armor( 30, 1 );
	set_natural_weapon( 90, 40, 40 );
	set("locked",0);
	set("faint",0);
	set( "time_to_heal", 20 );
	set( "max_hp", 2500 );
	set( "hit_points", 2500 );
	set( "gender","male" );
	set( "alignment",-1000 );
        set("stun_difficulty",100);
        set("special_defense", 
          ([ "all": 30,"none":30]) );
        set("aim_difficulty",
          (["critical":100]) );
        set("tactic_func","my_tactic");        
}  
void init()
{
    ::init();
    add_action("do_joke","joke");
}

int do_joke(string arg)
{ 
   object player;
   player=this_player();
   laugh = set_color(action[random(sizeof(action))],"HIY");
   tell_object(player,
     "\n『噗哇哈哈哈』,無支祈對著你大笑著說:你難道不知道 joke 的老祖宗是誰嗎?\n\n");
   tell_room(environment(this_object()),
         sprintf(laugh,"無支祈",player->query("c_name")));
   kill_ob(player);
   player->block_attack(6);
   player->set_temp("msg_stop_attack",
       "( 你現在笑得渾身沒力，無法攻擊！ )\n" );
   return 1;
}
int my_tactic()
{
    object *victim;
    int i;     

    if ( !victim=query_attackers() ) return 0;
    if (random(10)>1) return 0;

    laugh = set_color(action[random(sizeof(action))],"HIY");
    tell_room(environment(this_object()),
       sprintf(laugh,"無支祈","所有攻擊它的敵人"));
    for (i=0;i<sizeof(victim);i++) {
       victim[i]->block_attack(4);
       victim[i]->set_temp("msg_stop_attack",
          "( 你現在笑得渾身沒力，無法攻擊！ )\n" );
    }
    return 0;
}
void recover_or_die(object ob)
{
   object env;
   calloutcheck=0;
   env=environment(ob);
   if ( !ob->query("locked") ) {  
      tell_room(env,"\n忽然一聲大吼,無支祈又活了過來...\n\n");
      ob->set("hit_points",2500);
      ob->set("no_attack",0);
      ob->set("killer",1);
      ob->set("faint",0);
   }
   else 
     die(); 
}
void die()
{       
    object killer,obj;
    int wine;
    
    if ( !query("locked") ) {
       set("killer",0);
       set("no_attack",1);    
       cease_all_attacks();
       clean_up_attackers();
       set("hit_points",1); 
       tell_room(environment(this_object()),"無支祈一聲唉嚎,昏倒在地上!!\n");
       set("faint",1);
       if (!calloutcheck) {
         call_out("recover_or_die",60,this_object());  	
         calloutcheck=1;   
       }
    }
    else 
    ::die();
}
