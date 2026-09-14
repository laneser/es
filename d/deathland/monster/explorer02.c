#include "../echobomber.h"

inherit TEACHER;
inherit MONSTER;

void create()
{
	
	::create();
	set_level(14);
	set_name( "vampire explorer Simonleck","吸血鬼探險家西蒙雷克");
	add ("id", ({ "vampire", "explorer","simonleck" }) );
	set_short("吸血鬼探險家西蒙雷克");
	set_long(@DESC
吸血鬼探險家西蒙雷克,一個喜愛冒險的吸血鬼,曾經旅行過很多地方.
他的經歷豐富,如果你和他交談的話,你將可見到一個可以連續說話.
好幾天而不用喝水的超人.
DESC
    );
    set("alignment",-550);
    set( "gender", "male" );
    set( "race", "vampire" );
    set( "unit", "個" );
	set_perm_stat( "str", 20 );
	set_perm_stat( "kar", 22 );
	set ("wealth", ([ "silver": 200 ]) );
	set_natural_weapon( 26, 12, 15 );
	set_natural_armor( 80, 12 );
    set ("weight", 300);
    set ("chat_chance", 10);
    set("chat_output",({
        "這吸血鬼探險者笑著對你說:要不要聽聽我的故事(story)啊.\n"
        }));
    set_skill("dodge",90);
    set_skill("chain",100);
    set_skill("parry",70);
    set("special_defense",(["all":25]));
    set( "inquiry", ([
         "troll" : "@@ask_troll",
         "mine"  : "@@ask_mine" ,
         "hell"  : "@@ask_hell" ,
         "story" : "@@ask_story",
         "chain" : "@@ask_chain",
         ]) );
    wield_weapon(Weapon"/chain02");     
    set_lessons(([
       "chain": ( { 250,75 } )
       ]) );
}

void ask_story(object who)
{
    tell_object(who,"你想聽那一段故事?大戰巨人(troll),礦坑歷險(mine)\n或是神遊地獄(hell)呢?\n"
                );
    return ;
}

void ask_troll(object who)
{
     tell_object(who,@MSG1
有一次我不小心走進了巨人的領域,和可怕的巨人打了起來.
無論我如何的賣力,我就是無法把它給作掉,在數百回合之後
,我感覺到一種可怕的魔力慢慢地逼近我,在這麼多年的冒險
生涯裡,我從未像那一次做那麼正確的判斷,我以極快的速度
逃離,後來一個有經驗的矮人老戰士告訴我說,那是巨人大祭
師瑞哈得瑞德屈裡出巡的前召,而從沒有任何人能夠獨自見到
他而還活在這世界上的.
哈哈...
活著是件很快樂的,不是嗎?
MSG1
                 );
     return ;
} 

void ask_mine(object who)
{
     tell_object(who,@MSG2
矮人礦坑,一個充滿驚喜的地方,我曾拿著十字鎬到處地挖挖掘掘,
倒也發了一筆小財, 其中有一次我遇見了一隻奇怪的眼魔,我與它
的交手之中它身上的一件東西滿有趣的,當然我並不強求你,但是如
如果你能把它帶來給我的話,或許你能有意想不到的收穫呦.
MSG2
                 );    
     return;
}

void ask_hell(object who)
{
     tell_object(who,"地獄,你還沒有去過嗎,死一次你就知道了\n西蒙雷克笑笑著對你說\n");
     return ;
}

void ask_chain(object who)
{
     
     if (! (who->query_temp("echo_chain")) ) 
        {
          tell_object(who,"西蒙雷克搖搖頭說,我不知道.\n");
          return ;
        }
     else
       {
        tell_object(who,"我的流星錘技巧是一個東方武術家教的,你要學習嗎\n");  
        return ;
       }
}

int accept_item(object who,object item )
{
    if( (item->query("echo_chain_need")) )
      {
        who->set_temp("echo_chain",1); 
        if((string)who->query("class")=="knight")
          tell_object(who,@MSG3
謝謝你,假如你是個騎士的話,或許我可以教你流星錘(chain)
的技巧,但是你需要較高的經驗值去學習,因為我不是一個好老師.
MSG3
          );
        else 
          tell_object(who,@MSG4
謝謝你,我想你對於武器的領悟力不夠,我並不能幫助你什麼
但還是很感謝你.
MSG4
          );
        who->set_explore("deathland#35");
        item->remove();
        return 1;
      }
    tell_object(who,"謝謝你,我最喜歡收集物品了.\n");
    return 0;
}

int check_trainee(object who)
{
    if ((string)who->query("class")!="knight" || !who->query_temp("echo_chain"))
      return 0;
    else return 1; 
}
void init()
{
	teacher::init();
	npc::init();
}
