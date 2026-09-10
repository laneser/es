#include "../takeda.h"
#include "/include/move.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Silver Dragon","銀甲神龍" );
	add ("id", ({ "dragon" }) );
	set_short( "dragon","銀甲神龍");
	set("unit","尾");
	set_long(@C_LONG
這是一條有著美麗銀色鱗甲的巨龍，背上有著巨大且銳利的背甲
在傳說中它是具有不可思議力量的善良靈獸，任何武器只要浸入它的鮮血
就可以提升武器力量數倍。據說很久以前有個叫雷思的武士曾得到它的血
而製成龍血槍。
C_LONG	   
	);
	set( "likefish",1);
	set( "unbleeding",1);
	set("alignment",2700);
	set("max_hp",800);
	set ("time_to_heal", 1);
	set("hit_points",800);
	set_perm_stat("str", 30 );
	set_perm_stat("dex", 23 );
	set_perm_stat("kar", 25 );
	set_skill("dodge",100);
	set_natural_weapon( 80, 45, 72 );
	set_natural_armor( 130,60 );
	set ("gender", "male");
	set ("race", "monster");
	set_c_limbs(({"堅硬的背部","前頸","粗大的長尾","頭部"}));
	set_c_verbs( ({"%s揮舞龍爪抓向%s","%s龍吟一聲，龍尾狂掃向%s",
	"%s張嘴，一道火□噴向%s"}));
        set ("tactic_func","special_attack");
        set( "inquiry", ([
              "laice" : "@@ask_laice",
              "blood" : "@@ask_blood",
              "dragon" : "@@ask_dragon",
              "snake" : "@@ask_snake",
              "help" : "@@ask_help",
              "chiyu" : "@@ask_chiyu",
              "蚩尤" : "@@ask_chiyu",
              ]));
}
void ask_laice()
{
write (
      "銀甲戰龍突然很生氣的樣子，罵道: 那個該死的傢伙，說好要幫助我的，\n"
      "當我用自己的血(blood)強化他的武器後，他就不知所蹤了?\n");
      return ;
}

void ask_blood()
{
      write (
      "銀甲戰龍說道: 自從上次被雷思騙過之後，我再也不幫助任何人了！\n"
      "想要我的血，除非把我殺了，你要有興趣就來吧....\n"
      "說完，銀甲戰龍用鼻子向你臉上吹氣。\n");
      return ;
}
void ask_dragon()
{
      write (
      "銀甲戰龍說道: 龍是這世界最強大的生物....我的祖先就是傳說中的應龍...\n"
      "它曾幫助黃帝打敗蚩尤...\n" );
      return ;
}
void ask_snake()
{
      write (
      "銀甲戰龍說道: 你見過那條爛蛇嗎? 他是傳說中蚩尤的手下九嬰的後代。\n");
      return ;
}

void ask_help()
{
      write("我該相信你嗎? 銀甲戰龍懷疑的看著你......\n");
      call_out("ask_help2",10,this_player());
      return ;
}
void ask_help2()
{
      if ( this_player()->query("alignment") > 0 ) {
      write(@C_LONG
銀甲戰龍說道: 好吧，看你也不像個壞人，我就姑且相信你吧...
傳說中蚩尤(chiyu)在屯鹿戰死之後，他的手下九嬰逃到這個山洞，
秘密進行讓蚩尤復活的陰謀，而被我祖應龍發現了，於是它也進入這
個山洞並在這兒佈下結界以暗地進行破壞的任務，並將這個任務傳承
給它的子孫們。
C_LONG
            );
            call_out("ask_help3",10,this_player());
            return ;
            }
      write("你是壞人，一定是那隻爛蛇的手下....快滾開.....\n"
            "說完作勢欲撲.....\n");
            return ;
}
void ask_help3()
{
       write(@C_LONG
這麼多年來，由於我的祖先們的努力，那些邪惡的東西始終沒能找到
使蚩尤復活的關鍵物－[ 蚩尤的遺骸 ]，但最近我無意中得知，目前九嬰      
的後代具有極強的黑魔法能力，而它目前正在開發強力的定位搜尋魔法。
若是被它開發成功，不只我們這裡有危險，更可能被它先發現蚩尤的遺骸
到時若蚩尤復活，這世界就完了....
C_LONG
       );
             call_out("ask_help4",10,this_player());
             return ;
}
void ask_help4()
{
        write(@C_LONG
目前的當務之急是，在它們開發出定位搜尋魔法前，先找到蚩尤的遺骸
並且帶到我這裡來，如果你能作到這件事，我將會盡我所能的回報你
千萬不要試著挑戰那隻大蛇，如果你把它消滅掉，這個洞可能會發生危險
而這會使我失去了追蹤它們的線索....
你聽了它的話，心裡有點想幫助它，但又不知是否適當
不管怎麼說，先回去報告公孫先生你的發現似乎比較恰當...
C_LONG
              );
        this_player()->set_temp("find_something",1);
        return ;
}              
void ask_chiyu()
{
write("蚩尤是上古時的大魔頭，為了爭奪天下的霸權，與黃帝大戰於屯鹿之野。\n"
      "而這附近就是古時候的屯鹿....\n");
      return ;
}
void die()
{  
   object ob1,killer;
   
   killer = query("last_attacker");
   ob1 = killer->query("weapon1");
   if( !killer ) {
     ::die();
     return;
   }
   if( !ob1 ) {
     ::die();
     return;
   }
   tell_room(environment(this_object()),
      killer->query("c_name")+"一聲大吼，將手中的"+ob1->query("c_name")+"向銀甲戰龍用力插去...\n"+
      "\n銀甲戰龍狂吼不已，隆隆之聲不絕於耳，轉頭對"+killer->query("c_name")+"發出它臨終一擊 ！\n\n\n");
      killer->set("hit_points",10);
      "/d/magic/magic"->report( this_object(), killer );
   tell_room(environment(this_object()),
      "盡力一擊後，戰龍終於不支，吐血倒地而亡....\n"+
      killer->query("c_name")+"將插在戰龍□體上的"+ob1->query("c_name")+
      "拔出，順手把上面的血跡擦拭乾淨。\n"      
      );
   ob1->add( "min_damage",5 );
   ob1->add( "max_damage",5 );
   ::die();   
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
       
       
int special_attack()
{// 10% use it! damage 30-50.
    object env,*inv,*victim;
    int i;
    env=environment(this_object());
    inv=all_inventory(env);
    if(random(10)<8) return 0;
    tell_room( environment( this_object() ), 
      "\n\n [1;41m 銀龍噴出一團炙熱煉火，燒得所有人如處於煉獄般． [0;40m \n\n\n" ,
      this_object()
    );
    this_object()->receive_healing(10);
    i = sizeof(inv);
    while(i--) {
      if (inv[i]!=this_object()) 
        {
           inv[i]->receive_special_damage("fire",random(20)+30);
           "/d/magic/magic"->report( this_object(), inv[i] );
        }
    }
    return 1;
}

