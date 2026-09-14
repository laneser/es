#include "../legend.h"

string *cast_msg1=
     ({ "%s開始凝聚空氣中的風因子在他的周圍形成巨大的暴風！\n",
        "%s口中開始冒出陣陣的白煙，噴出些微火星!\n",
        "%s喃喃自語，空氣中的光因子不斷地聚集!\n" }),
       *cast_msg2=
     ({ "%s身旁的暴風急速地往眾人面前刮過，你感到一陣火辣辣的刺痛！\n\n",
        "\n%s口中大喊「三昧真火」，漫天烈焰往你身上澆去，使你炙痛難當!\n\n",
        "%s周圍一道強大的光量籠罩著整個房間!\n\n\n\n" }) ;
inherit MONSTER;
void create()
{
	::create();
	set_level(18);
	set_name( "fisher captain","村長" );
	add ("id", ({"captain"}) );
	set_short("漁村 村長");
	set_long(@C_LONG
村長年約四、五十歲，一副紳士的樣子，看起來蠻友善的，可是，他一發起脾氣來
是非常恐怖的；他的臂力，據說可以打死九頭牛；他的吼聲，震死六隻大象都綽綽
有餘；所以，你最好不要招惹他喲。村長同時是村裡最具有權威的人，平時掌管漁
村裡頭大大小小的事務，可說是非常忙碌。村長最近在跟老漁翁學習一些東西，當
然，如果能因此改改他的脾氣，那是再好不過的。村長現在愁眉沈鎖，似乎遇到了
什麼麻煩了。
C_LONG
	);
	set( "unit", "名" );
	set_perm_stat( "str", 27 );
	set_perm_stat( "dex", 24 );
	set_perm_stat( "kar", 30 );
        set("weight",900);
        set_skill( "unarmed-parry", 80);
	set_skill( "dodge", 80 );
	set("max_sp",2700);
        set("spell_points",2700);
	set_temp("be_joke",100);
	set("hime_to_heal",4);
	set( "special_defense", ([ "all": 50,"none":50,
	"monk":40,"scholar":20]) );
	set( "stun_difficulty",50);                                              
	set("aim_difficulty", 
	   ([ "critical":100, "vascular":60, "ganglion":70, "weakest":30 ]) );
	set( "gender", "male" );
	set( "race", "human" );
	set("max_hp", 900);
	set("hit_points",900);
	set_natural_armor( 60,35 );
	set_natural_weapon( 72,29,55);
        set_temp("detect_hide",1);
        set_temp("detect_invi",1);
        equip_armor(LARMOR"fish_cloth");
//	set( "tactic_func", "my_tactic" );
        set( "inquiry", ([
             "trouble":"@@ask_trouble",
                "麻煩":"@@ask_trouble" 
        ]) );
}
void ask_trouble(object asker)
{
   if ( asker->query_temp("second") ) {
      tell_object(asker,"村長很傷心地哭著。\n");   
      return ;   
   }
   if ( asker->query_temp("captain_asked") ) {
      tell_object(asker,"村長道：拜託你了。\n");
      return ;
   } 
   asker->set_temp("captain_asked",1);
write(@C_LONG
村長道嘆了一口氣道：唉，我本有個青梅竹馬的女友，己經到了論及婚嫁的程度，活
　　　　　在愛情的滋味裡是那麼地美好，我深信，當時的我應該是我一生中最快樂
　　　　　的時光。不幸地，有一天，當她一個人信步地走在海堤上，猛地，一個大
　　　　　浪把她給捲到了海里去，事後，我派過無數不乏精通水性的人去尋找她的
　　　　　縱跡，卻一直音訊全無，至今不知是生亦或者是死。唉！二十多年以來，
　　　　　我茶不思飯不想，無時不刻不念及她，現在，我願奉獻我所有的一切，只
　　　　　為能換得她一絲的容顏。少俠，你能幫我去找尋她嗎？唉．．．

村長喃喃自語道：「小漁，小漁，你知道我是多麼地想念你嗎．．．
C_LONG
     );
} 
int my_tactic()
{
    object victim,env;
    string mob_name,msg1,msg2,type;
    int damage;
    if ( !victim=query_attacker() ) return 0;
    env=environment(this_object());
    mob_name=query("c_name");
    switch( random(50) ) {
    case 1..5:
       msg1=set_color(cast_msg1[0],"HIB");
       tell_room(env,sprintf(msg1,mob_name));
       msg2=set_color(cast_msg2[0],"HIB");    
       type="energy";
       damage=55+random(10);
       call_out("cast_run",3,type,msg2,mob_name,damage);
       break;
    case 6..10:
       msg1=set_color(cast_msg1[1],"HIR");
       tell_room(env,sprintf(msg1,mob_name));
       msg2=set_color(cast_msg2[1],"HIR");
       type="fire";
       damage=80+random(25);
       call_out("cast_run",5,type,msg2,mob_name,damage);
       break;
    case 11..15:
       msg1=set_color(cast_msg1[2],"HIY");
       tell_room(env,sprintf(msg1,mob_name));
       msg2=set_color(cast_msg2[2],"HIY");
       type="electric";
       damage=65+random(20);
       call_out("cast_run",4,type,msg2,mob_name,damage);
       break;
    }
    return 0;              
}
void cast_run(string type,string msg,string mob_name,int damage)
{
   object env,*all;
   int i;
   env=environment(this_object());
   all=all_inventory(env);
   tell_room(env,sprintf(msg,mob_name));
   for (i=0;i<sizeof(all);i++)
      if ( all[i]!=this_object() ) 
         all[i]->receive_special_damage(type,damage);      
}
void relay_message(string class, string msg)
{

     string who, str;
     object player;

     ::relay_message(class, msg);
     if( sscanf( msg, "%s(%s)走了進來。", str,who )==2 ) {
     if( !player = find_player(lower_case(who)) ) return;
     if( !player->query_temp("wife_asked") ) return ;
     player->delete_temp("wife_asked");
     player->delete_temp("captain_asked");
     player->set_temp("second",1);
     tell_object(player,@C_LONG
村長看見你帶來給他「少女小漁」已死的訊息不由得痛哭了一場，了了不能自己．．

你看他哭成這樣子，不忍心去打擾他。你不禁感嘆，唉！真是造化弄人，倘若可使有
情人終成眷屬，也許，世上會少了一半傷心的人了。　

C_LONG
     );                                                               
     }
}