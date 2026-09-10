#include "../takeda.h"
#include "/include/move.h"
#include "conditions.h"
#include "stats.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Gold Snake", "金鱗鬼蟒" );
	add ("id", ({ "snake" }) );
	set_short( "snake","金鱗鬼蟒");
	set("unit","尾");
	set_long(@C_LONG
你看到一條非常巨大的蟒蛇，粗糙的外皮就如同石頭般堅硬，表面長滿
了許多金色鱗片，泛起的金光使你看不清原來的紋路，仔細看看似乎有
一股邪氣籠罩著它。它現在正在抬頭到處張望，不知道它在幹嘛，也許你
能夠幫助它喔...
C_LONG
	);
	set( "likefish",1);
	set( "unbleeding",1);
	set("alignment",-3500);
	set_perm_stat("str", 25);
	set_perm_stat("dex", 28);
	set_perm_stat("kar",22);
	set_natural_weapon( 65, 32, 56 );
	set_natural_armor( 75, 30 );
	set ("tactic_func","poison");
	set_skill("dodge",100);
	set_skill("target",100);
	set_skill("black-magic",100);
	set_skill("concentrate",100);
	set("magic_delay",2);
	set("spells/ether-bolt",8);
	set ("gender", "male");
	set ("race", "monster");
	set_c_limbs(({"堅硬的鱗片","長長的蛇身","巨大的蛇頭","粗大的尾巴"}));
	set_c_verbs( ({"%s捲動整個身體，猛然襲向%s","%s用身體緊緊的捲住%s","%s噴出一股強勁毒液，射向%s"
	,"%s張開血盆大口，一口咬向%s"}));
        set( "inquiry", ([
              "cycle": "@@ask_cycle",
              "蚩尤" : "@@ask_chiyu",
              "lair" : "@@ask_lair",
              "dragon" : "@@ask_dragon",
              "help" : "@@ask_help",
              "chiyu" : "@@ask_chiyu",
              "chuyin" : "@@ask_chuyin"
              ]));
}
void evil_damage()
{
     if ( find_call_out("evil")==-1 )
            call_out("evil",5,0);
}
void init()
{
     ::init();
     evil_damage();
}
void evil(int call_again)
{
     object npc,room,*player;
         int i;
          
         npc=this_object();
         room=environment(npc);
         player=all_inventory(room);
         for(i=0;i<sizeof(player);i++)
         if ( living(player[i]) && player[i]!=npc ) {
         tell_object(player[i],
         "從金鱗鬼蟒身上發出強烈的妖氣震傷了你.\n");
         player[i]->receive_special_damage("evil",10+random(20));
         "/d/magic/magic"->report( this_object(), player[i] );
         }
         call_again++;
         if ( call_again<5 ) call_out( "evil", 8 , call_again );
         }

void ask_lair()
{
write (@C_LONG
你感到金鱗鬼蟒在你的心中說道: 這個洞穴是我的祖先九嬰(chuyin)所建立的，
C_LONG);
      return ;
}
void ask_cycle()
{
write (@C_LONG
你感到金鱗鬼蟒在你的心中說道: 這個魔法陣是我一手建立的
用來開發一些更強力的黑魔法
C_LONG);
      return ;
      }
void ask_chuyin()
{
      write (@C_LONG
你感到金鱗鬼蟒在你的心中說道: 九嬰是我們一族最偉大的英雄，不僅勇武
非凡，更兼法力高強，他傳下的黑魔法能力，雖然經過無數祖先的鑽研，到
我也大概只能學到八成而已...
C_LONG);     
      return ;
}
void ask_dragon()
{
      write (@C_LONG
你感到金鱗鬼蟒在你的心中說道: 龍是這世界第二強大的生物....第一強大就是
我們妖蛇族
C_LONG );
      return ;
}
void ask_help()
{
      write("金鱗鬼蟒冷冷的看著你......\n");
      call_out("ask_help2",10,this_player());
      return ;
}
void ask_help2()
{
      if ( this_player()->query("alignment") < 0 ) {
      write(@C_LONG
你感到金鱗鬼蟒在你的心中說道: 喔，你好像蠻合我的胃口的，我就把你
當成我的手下吧，傳說中蚩尤在屯鹿戰死之後，英雄九嬰(chuyin)逃到這個山
洞，開始進行讓蚩尤(chiyu)復活的光榮任務。
C_LONG
            );
            call_out("ask_help3",10,this_player());
            return ;
            }
      write("金鱗鬼蟒說道: 你是好人，正好我有點餓了.....\n"
             "你覺得它對你不懷好意，主動發動攻擊....\n");
      this_object()->kill_ob(this_player());
            return ;
}
void ask_help3()
{
       write(@C_LONG
這麼多年來，由於我的祖先們的努力，所需要的一切咒文及技術都已準備好
了，唯獨欠缺使蚩尤復活的關鍵物－[ 蚩尤的遺骸 ]，目前我正在開發強力
的定位搜尋魔法，以便於早日尋找到它以使蚩尤復活..
C_LONG
       );
             call_out("ask_help4",10,this_player());
             return ;
}
void ask_help4()
{
        write(@C_LONG
不過雖然我的魔法已接近完成，不過最快大概也還要三年
不過在開發這個魔法時，我發現似乎存在另一股力量在阻止我們的任務
若再等三年，不知道會有什麼變化發生，所以若你能夠在這三年中，先
找到蚩尤的遺骸並且帶到我這裡來，你將會因此而得到很大的報酬...
你聽了它的話，心裡有點想幫助它，但又不知是否適當
不管怎麼說，先回去報告公孫先生你的發現似乎比較恰當...
C_LONG
              );
        this_player()->set_temp("find_something",1);
        return ;
}              
void ask_chiyu()
{
write("蚩尤是我們一族的領袖，為了爭奪天下的霸權，與黃帝大戰於屯鹿之野。\n"
      "而這附近就是古時候的屯鹿....\n");
      return ;
}
void announce( string msg, string c_msg )
{
	object *usr;
	int i;

	usr = users();
	for( i=0; i<sizeof(usr); i++ ) {
		if( !environment(usr[i]) ) continue;
		tell_object( usr[i], can_read_chinese(usr[i])? c_msg: msg );
	}
}
void die()
{  
   object ob1,killer,ob2,ob3;
   
   killer = query("last_attacker");
   if( !killer ) {
     ::die();
     return;
   }
      tell_room(environment(this_object()),
            "\n金鱗鬼蟒一聲嘶吼，一頭往山壁撞去想要逃跑，不料體力透支，竟一頭\n"
            "撞死在山壁上。四周的山壁經它這麼一撞，一大堆落石乒乒乓乓的滾了下來..\n\n");
   ob1 = new("/d/adventurer/natural_history/stone");
   ob1->move(TROOM"lair/lair5");         
   ob2 = new("/d/adventurer/natural_history/stone");
   ob2->move(TROOM"lair/lair5");
   ob3 = new(TOBJ"rock");
   ob3->move(TROOM"lair/lair5");
   tell_room( environment(ob3),
   "\n你看到許多大大小小的石頭從山上滾下來，你集中全部的注意力閃躲，總算\n"
   "沒有打到你...\n");
   ::die();   
}


int poison()
{
	object victim;

	if( random(20)>4 || !(victim = query_attacker()) ) return 0;
	if( random(3) < 1 ) {
	tell_object( victim, 
		set_color("\n金鱗巨蟒血口一張，一團綠色毒霧向你襲來！\n","HIG",victim));
	tell_room( environment(this_object()), 
		"金鱗巨蟒巨口大開，一團毒霧向" + victim->query("c_name") + "的面門罩下！\n"
		, victim  );
	SIMPLE_POISON->apply_effect( victim, 8, 10 );
	return 1;
	}
	command("cast ether-bolt on "+victim->query("name"));
	this_object()->receive_healing(30);
	return 1;
}
