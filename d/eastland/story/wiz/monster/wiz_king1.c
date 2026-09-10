#include "../../story.h"
#include "../../magic.c"
inherit MONSTER ;
void create ()
{
	::create();
	set_level(19);
	set_name( "King of wizard", "巫羅王" );
	add ("id", ({ "king","wizard"}) );
	set_short( "城主 巫羅王");
	set_long(@CLONG
你眼前所見的是一位文質彬彬，身子修長年紀看似不很大的人正坐在龍椅上。巫羅
王的五官長得秀美極了，光是那一對招子，有若寒星點點散發出閃閃銀光，在深墜
的眼眸裡，令人一看內心就會感到陣陣平和。巫羅城主英明有智慧，善納諫言，擢
拔人才，他的膽識與氣度相當不凡，其駕御能力更是令人望塵莫及，生平歷經無數
戰役鮮有敗績，傷亡更是減到最低程度，他不啻是位令人信賴的好夥伴，亦是位讓
人尊敬的好上司。不知怎麼搞的，你發現巫羅王的神色中似乎帶著一些煩憂 (trou
ble)。 
CLONG
	);
	set("flute",1);
	set("race","human");
        set("race","巫師");
	set("gender","male");
	set_perm_stat("str", 30 );
        set_perm_stat("dex", 30 );
        set_perm_stat("kar", 30 );
        set_perm_stat("int", 30 );
	set( "alignment", 5000 );
	set( "hit_points", 2000 );
	set( "max_hp", 2000 );
        set( "max_fp",500);
	set_natural_weapon( 25, 30, 45 );
	set_natural_armor( 86, 55 );
        set("aim_difficulty",([ 
    	  "critical":80,"vascular":80,"ganglion":80,"weakest":80 ]) );
        set("wealth/gold",500);
        set("stun_difficulty",100);
        set("conditions/_heal_hp",({ 3 , 1 }) ) ;
        set_skill("parry",100);
        set_skill("block",100);
        set_skill("jousting",100);
        set_skill("two-weapon",100);
        set("tactic_func","my_tactic");
        wield_weapon(SWWEA"wiz_lance");
        equip_armor(SWARM"wiz_shield3");
        equip_armor(SWARM"wiz_ring2");
        equip_armor(SWARM"wiz_cloak1");
        equip_armor(SWARM"wiz_helmet1");
        set("special_defense",(["all":50,"none":40,"monk":40]));
        set("inquiry",([
              "great_bag":"@@ask_bag",
              "fly_flute":"@@ask_flute",
                "trouble":"@@ask_trouble",
        ]) );
}
int accept_item(object player, object item)
{
      string iname,pname,pcname;
      
      if ( !item->query("spiritball") ) {
         tell_room(environment(),"巫羅王說道：給我這東西幹嘛？我又不是收垃圾的。\n");
         item->move(environment());
         return 1;      
      }
//    if ((int)player->query_quest_level("wizking")>0 ) {
      if ((int)player->query("quests/wizking")>0 ) {
         write("巫羅王說道：謝謝你再次幫忙。\n");
         return 1;
      } 
      iname=item->query("master");
      if (!(pname=player->query("org_name"))) pname=player->query("name");
      pcname=player->query("c_name");
      if ( iname!=pname ) {
         tell_room(environment(),sprintf(
           "巫羅王對著%s喊道：原來就是你偷的，給我去死吧！！\n",pcname),player);
         tell_object(player,"\n巫羅王對你喊道：原來是你偷的，給我去死！\n\n"); 
         kill_ob(player);
         item->remove();
         return 1;
      }
      write(@LONG
      
 巫羅王說道：謝謝你幫我找回巽靈珠。

 [ 由於你熱心地解決了巫羅王的困難，因而獲得巫羅王賞賜的 15000 點的經驗值]    

LONG
      );
      // player->finish_quest("wizking",1);
      player->set("quests/wizking",1);
      player->gain_experience(15000);
      item->remove();
      return 1;
}
void ask_trouble(object asker)
{
  write(@LONG
巫羅王說道：唉，我把鎮城之寶－巽靈珠(spirit_ball)給弄丟了，你能幫我找
            回來嗎？詳細情形你去問護國師好了，我現在沒心情跟你討論。
              
LONG
  );
}
void ask_flute(object asker)
{
   object flute;
   if( !asker->query_temp("flute_asked",1) ) {
     write("巫羅王說道：哼，無恥小賊，你到底是從那裡打聽到「飛翔之笛」的？\n");
     return ;
   }
   write("巫羅王說道：哦，原來是羽後跟你說要來拿回「飛翔之笛」的喔？\n");
   if( !query("flute") ) {
     write("巫羅王嘆道：我已經把笛子給別人了，你似乎來的太晚了。\n");   
     return ;
   }
   flute=new(SITEM"flute1");
   if (flute->move(asker)!=0) {
     write("巫羅王說道：你帶太重了，丟一些東西掉吧。\n");
     flute->remove();
     return ;
   }
   set("flute",0);
   flute->move(asker);
   write(@LONG
巫羅王說道：好吧，我就給你吧。
巫羅王給你一個「飛翔之笛」。
巫羅王續道：「飛翔之笛」現在業已沒有能源(flute_energy)了，你自已想個辦法吧。
LONG
   );
   tell_room(environment(),"巫羅王露出狡猾的微笑。\n");
   asker->delete_temp("flute_asked");
   call_out("back",300);
   return ;
}
void back()
{
   set("flute",1);
}
int get_bag(string name,string *names)
{ 
    int i,max;
    max=sizeof(names);
    for (i=0;i<max;i++)
      if ( name==names[i] ) return 1;
      else return 0; 
}        
void ask_bag(object asker)
{
    object env,bag,*get,ball;
    string name,*names;
    if ( !asker->query("quests/wizking") ) {
       write("巫羅王說道：嗯，無底袋是我城內的特產。\n");
       return ;
    }
    if (!(name=asker->query("org_name"))) name=asker->query("name");
    env=environment(this_object());
    names=env->query("bag_asked");
    if (!get_bag(name,names)){
       write("\n巫羅王說道：看在你幫我找回巽靈珠的份上，我就給你一個無底袋。\n\n");
       env->add("bag_asked",({name}));     
       tell_object(asker,@LONG

只見巫羅王把手舉向天空並且喃喃自語....

嚇！忽然從空中掉下一個無底袋來！！

巫羅王說道：嗯，好孩子，這是賞給你的，^_^。

LONG
       );
       bag=new(SWITEM"bag1");
       bag->set( "max_load", 1500);
       bag->set( "weight_apply", 25 );
       bag->set("no_sale",1);
       bag->move(env);      
       return ;
    }       
    tell_object(asker,"巫羅王以質疑的眼光看著你：咦，你不是已經跟我要過一個無底袋了嗎？\n");
    return ;
}
void init()
{
   ::init();
   add_action("do_embattle","embattle");
   add_action("do_demand","demand");
}
int can_help( object ob )
{
   if ( !living(ob) ) return 0;
   if ( ob->query("bodyguard") ) return 1;
   return 0;
}

int stop_attack()
{
    int i,max;
    object *tmp, env, *atk;
        
    env=environment();
    atk=filter_array(all_inventory(env),"can_help",this_object());
    max=sizeof(atk);
    for ( i=0;i<max;i++ ) {
        tell_room( env,sprintf(
           "%s衝到巫羅王面前，並且大聲喊道：有刺客，大家快保護城主的安全！\n"
           ,atk[i]->query("c_name")) );
        tmp = query_temp( "protectors" );
        if( !tmp || member_array( atk[i], tmp )==-1 ) {
           add_temp( "protectors", ({ atk[i] }) );
           atk[i]->add_temp( "protectees", ({ this_object() }) );
        }
        atk[i]->kill_ob(this_player());
    }
    return 0;
}
int do_embattle(string arg)
{
   object player;
   player=this_player();
   if ( player->query("class")!="scholar" ) return 0; 
   write("巫羅王看穿了你想結陣法的企圖，於是給你一個重重的痛擊！\n");
   player->add("hit_points",-20);
   player->add("spell_points",-40);
   return 1;
}
int do_demand(string arg)
{
   object player;
   player=this_player();
   if ( player->query("class")!="scholar" ) return 0;
   write("巫羅王把你所招喚的精靈一口吃了下去！\n");
   player->add("spell_points",-40);
   add("hit_points",200);
   return 1;
}
int my_tactic()
{
    int i;
    object victim,env;
    string name;
    
    if ( !victim=query_attacker() ) return 0;
    env = environment( this_object() );
    name=victim->query("c_name");
    switch(random(60)){
    case 0..3 : 
        tell_object(victim,set_color(
           "\n\n糟糕！巫羅王似乎發現了你的致命弱點！\n\n","HIW"));
        tell_room(env,sprintf(
           "巫羅王發現了%s的致命弱點！\n",name),victim);
        victim->set("hit_points",victim->query("hit_points")/3);
        return 1;
    case 4..9:    
        tell_object(victim,
        "\n巫羅王手中的霸王槍宛如一條靈蛇，對著你連刺三十六槍，槍槍致命！\n\n");
        tell_room(env,sprintf("巫羅王對著%s連刺好幾槍!\n",name),victim);
        victim->receive_damage(70+random(10));
        report(this_object(),victim);
        return 1;
    default :
        return 0;
    }   
}
