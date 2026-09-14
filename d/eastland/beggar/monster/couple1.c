#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "the elder of couples", "鶴老" );
	add("id",({"couple","couples","elder"}) );
        set_short( "天山二老 鶴老" );
	set_long(@C_LONG
天山二老在江湖上極具身份與地位, 十多年前一役擊殺為害多時的『廣東六虎』,
更而倍受武林人士所推祟。鶴老是天山二老中較年老者, 看起來□□長長的,雙指
尖而且銳利,一看就知道練有某種極其厲害的爪法。這次應丐幫之邀參加一年一度
的祭祖大典,想必,大典生色不少 !!
C_LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment",100 );
	set( "time_to_heal", 7 );
	set_natural_armor( 40 , 40 );
	set_natural_weapon( 50 , 25 , 40);
	set("max_hp",600);
	set("hit_points",600);
	set("force_points",500);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex",25 );
	set_skill( "parry",50 );
	set( "wealth/silver",200);
	set( "special_defense", ([ "all": 22 ]) );
	set( "aim_difficulty",(["critical":70,"vascular":30,"weakest":50]) );
	set("couple",1);
        set_c_verbs( ({ "%s使出『 赤 煉 爪 』第一式, 單手打向%s",
                        "%s俯身而下使出『 赤 煉 爪 』第二式, 雙手凌厲已極抓向%s",
                        "%s吼叫一聲, 『 赤 煉 爪 』第三式向%s欺了過來",
                        "%s化爪為掌使出『 赤 煉 爪 』最強一式,漫天手影向%s打了過來"
                      }) ); 
        equip_armor(DARMOR"couple_cloak");
        set( "tactic_func", "my_attack" );
        set("inquiry", ([
                 "pill":"@@ask_pill"
        ]) );
        set( "chat_chance", 30 );
        set( "att_chat_output", ({
              "天山二老 鶴老狂笑道:不好好修理你,你是不會覺悟的!! \n"
           }) );
} 

void ask_pill(object asker)
{

   if ( this_object()->query("have_asked") )
      tell_object( asker,
         "天山二老 鶴老說道:唉,這位好漢你來晚了,我才把熊蛇丸給別人...\n");
   else {
     this_object()->set("have_asked",1);
     tell_object(asker,
         "天山二老 鶴老說道:哦,你問九轉熊蛇丸喔?\n"
         "接著你向他表明了你的來意。\n"
         "天山二老 鶴老說道:請等一下。\n\n"
         "他思考了一會兒。\n\n"
               );
     call_out("recover1",3,asker);             
     call_out("recover2",1800,this_object());
   } 
}
void recover1(object obj)
{ 
   object ob1;
   ob1=new(DITEM"pill");
   ob1->set("master",obj->query("name"));
   tell_object(obj,
      "天山二老 鶴老說道:既然你要拿來救人,那我就給你一顆吧。\n"
         );
   ob1->move( this_object() );
   command("give pill to "+obj->query("name"));
   tell_object(obj,
      "天山二老 鶴老說道:請不要浪費熊蛇丸喔,這是我很不容易才煉成的。\n"
      "你向天山二老 鶴老點了點頭。\n"
               );
}
void recover2(object obj)
{
    obj->delete("have_asked");
}

int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
       return 0;
}

int my_attack()
{ 
   object *couples,victim;
   int i;

   victim = query_attacker();
   if( !victim ) return 0;
    
   couples = filter_array( all_inventory(environment(this_object())),
           "can_help", this_object() );
   for( i=0; i<sizeof(couples); i++ ) {
      tell_room( environment(this_object()), couples[i]->query("c_name")+
          "怒道:我們豈是那麼好欺負的,給我下地獄去吧!!\n",
          couples[i]);
      couples[i]->kill_ob(victim);
   }

   if  (random(5)>1)  return 0;
   else{
       tell_room( environment(this_object()),set_color(
           "\n嚇!突然間鶴老手掌變成黑色碧油油的嚇人,打在"+
           victim->query("c_name")+"的胸前......\n","HIG",victim),victim);
       tell_object( victim,set_color(
           "\n嚇!突然間鶴老手掌變成黑色碧油油的嚇人,打在你的胸前......\n","HIG",victim));
       (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 5 , 3 );
       return 1;
   }      
}


void die()
{
    object ob1,last_hit;
    
       last_hit=this_object()->query("last_attacker");
       if ( ( !(last_hit->query_temp("have_ball"))) &&
            ( last_hit->query("class")!="healer" ) 
       ){
           last_hit->set_temp("have_ball",1);
           ob1 = new( DITEM"ball" );
           ob1->move(last_hit);
           tell_object(last_hit,"\n嚇!!你眼明手快地從"
               +this_object()->query("c_name")+"屍體中取出舍利子\n\n");
        }::die(1);
 }