#include "mudlib.h"
#include <daemons.h>
#define AIM ({ "ganglion","vascular","weakest"})

inherit "/d/adventurer/adv_trainer";
inherit MONSTER;

void init()
{
npc::init();
adv_trainer::init();
add_action("do_list","list");
}
void create ()
{
 //   int i;
 //   i = random(2);
	::create();
    set_level(19);
    set_name("Great Avery","大冒險家  艾佛瑞");
    add("id",({"avery","great","adventurer"}) );
    set_short("大冒險家  艾佛瑞");
	set_long(@C_LONG
    大冒險家  艾佛瑞是亞默長老最得意的弟子，不僅盡得亞默長老的真傳，更在他冒
險的生涯中，學得了許多新技巧。這次他是受亞默長老所託，在此訓練立志以冒險為終
身職業的冒險者。
他現在正用著一種高傲不屑的眼光打量著你。
C_LONG
	);
    set("alignment",1000);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "個" );
    set_perm_stat( "dex",30);
    set_perm_stat( "str",28);
    set_perm_stat( "int",20);
    set_perm_stat( "karma",30);
    set_skill("whip",100);	
    set_skill("dodge",80);
    set_skill("parry",100);
    set_skill("anatomlogy",55);
    set ("max_hp",1300);
    set ("hit_points",1300);
    set( "chat_chance",12);  
    set("chat_output",({"艾佛瑞自言自語: 都是些扶不起的阿斗...\n"}));
    set ("wealth", ([ "gold":300]) );
    set_natural_weapon(35,22,34);
    set_natural_armor(70,40);
    set ("aim_difficulty",([ "weakest":50,"vascular":30]) );
    set("special_defense", (["fire":90,"none":20]) );
    set( "aiming_loc", "weakest" );
//    AIM[i] );
    set( "tactic","berserk" );
    set ("weight", 400);
    wield_weapon( "/d/adventurer/hall/weapons/avery_whip" );
    set("inquiry",([
        "train" : "@@ask_train",
        "polemic" : "@@ask_polemic", 
        "trading" : "@@ask_trading",
        "ethics" : "@@ask_ethics",
        "diagnose" : "@@ask_diagnose",
        "hang" : "@@ask_hang",
        "natural_history" : "@@ask_natural",
        "green-magic" : "@@ask_green"
        ]));
    set("tactic_func","special_attack");
    set_lessons( ([
	"polemic": ({ 120, 50, 10 }),
	"trading": ({ 150, 70, 10 }),
	"ethics": ({ 130, 50, 20 }),
	"diagnose": ({ 120, 60, 20 }),
	"hang": ({ 220, 90, 50 }),
        "natural_history": ({ 150, 100, 40 }),
        "target": ({ 200, 50, 70 }),
      "concentrate": ({ 200, 50, 70 }),
        "green-magic": ({ 200, 50, 70 }) 
	]) );
}
int special_attack()
{
        int i;
        if(random(10)<7) return 0;
        i = random(2) ;
        set( "aiming_loc", AIM[i] );
        return 1;
}        

void ask_natural()
{
   if ((string)this_player()->query("class") != "adventurer" ) {
       write("大冒險家  艾佛瑞說道: 回你自己工會去吧...\n");
           return ;
   }
   
   write("大冒險家  艾佛瑞說道: 博物學可以讓你認識一些常見的自然物，你可\n"
         "以用 explore 指令在野外尋找到他們。你可以打help explore得到更多\n"
         "的資訊。\n");
   return ;
}
void ask_train()
{  
     if ((string)this_player()->query("class") != "adventurer" ) {
     write("大冒險家  艾佛瑞說道: 回你自己工會去吧...\n");
    return ; 
     }
     write("大冒險家  艾佛瑞說道: 沒錯，我可以教你們一些平常學不到的技能。\n"
           "但前提是平均冒險度要夠高，你可以用list指令來看目前你能學什麼。\n");                     
    return ;
}
void ask_polemic()
{  
    if ((string)this_player()->query("class") != "adventurer" ) {
    write("大冒險家  艾佛瑞說道: 回你自己工會去吧...\n");
   return ;
    } 
    write("大冒險家  艾佛瑞說道: 學會辯術，你將擁有說服他人的能力，遭受敵人攻擊時\n"
    "也可以利用賄賂(bribe)使敵人停止攻擊你，可說是一個保命的技能。\n");
   return ;
}
void ask_trading()
{  
    if ((string)this_player()->query("class") != "adventurer" ) {
    write("大冒險家  艾佛瑞說道: 回你自己工會去吧...\n");
    return ;
    }
    write("大冒險家  艾佛瑞說道: 學會交易技巧，可使你買賣物品的技巧更為高超，不但\n"
    "不會被奸商欺騙，還可以從中獲得應有的利益，可說是一個賺錢的技能。\n");
   return ;
}
void ask_ethics()
{  
    if((string)this_player()->query("class") != "adventurer" ) {
    write("大冒險家  艾佛瑞說道: 回你自己工會去吧...\n");
    return ;
    }
    write("大冒險家  艾佛瑞說道: 倫理學主要在教人明辨是非，知道什麼是對的，什麼\n"
    "是錯的，如果你在倫理學上下功夫的話，就可以從一個人的言行舉止，大致上判\n"
    "斷出一個人的善惡，這個技能在你使用consider 指令的時候會自動使用。\n");
   return ;
}
void ask_diagnose()
{  
    if((string)this_player()->query("class") != "adventurer" ) {
    write("大冒險家  艾佛瑞說道: 回你自己工會去吧...\n");
    return ;
    }
    write("大冒險家  艾佛瑞說道: 診斷這個技能能夠使你知道自己或他人的狀態\n"
    "在攻擊或防禦時知道敵人的狀態，能夠使你遠離危險。\n"); 
   return ;
}
void ask_hang()
{
    if((string)this_player()->query("class") != "adventurer" ) {
    write("大冒險家  艾佛瑞說道: 回你自己工會去吧...\n");
    return ;
    }
    write("大冒險家  艾佛瑞說道: 絞殺這個技能能夠使你使用長鞭類武器\n"
          "絞殺敵人，若施術成功，敵人會受傷且暫時不能行動。\n");
          return ;
    }
void ask_green()
{
    if((string)this_player()->query("class") != "adventurer" ) {
    write("大冒險家  艾佛瑞說道: 回你自己工會去吧...\n");
    return ;
    }
    write("大冒險家  艾佛瑞說道: 極高等級的冒險者，由於累積了許多的\n"
          "經驗與智慧，因此具有基本的綠魔法能力，但是我並不教授咒文\n"
          "你需要自己去發現並學習它 。\n");
    return ;
    }



int check_trainee(object trainee)
{
    if( (string)trainee->query("class")=="adventurer" && (int)trainee->query_level() > 4 )
    return 1;
    else
    return notify_fail(
    "大冒險家  艾佛瑞說道: 我只教夠資格的冒險者，你的條件不合！\n");
}
int do_list()
{
     int explore,total_points,EXPLORE1;
     explore  = (int)this_player()->query_explore_points();
     total_points=EXPLORE_D->query_total_explore(); 
     EXPLORE1=explore*10000/total_points;
     if (EXPLORE1 > 10000) EXPLORE1 =10000;
     if((string)this_player()->query("class") != "adventurer" ) {
     write("大冒險家  艾佛瑞說道: 回你自己工會去吧...\n");
     return 0;
     }
     if ( EXPLORE1 < 1000 ) {
     write("艾佛瑞說道: 以你目前的能力，還不能在我這兒學習任何技能...\n");
     return 1;
     }
     write("在這裡你所能訓練的技能有:\n");
if ( EXPLORE1 > 6999 )
    write("\n    目標(target)                   ( 經驗值比例 = 200%, 上限 =  50 )"
 "\n    專心(concentrate)              ( 經驗值比例 = 200%, 上限 =  50 )" 
"\n    綠魔法(green-magic)            ( 經驗值比例 = 200%, 上限 =  50 )");  
     if ( EXPLORE1 > 4999 )
     write("    絞殺(hang)                     ( 經驗值比例 = 220%, 上限 =  90 )");
     if ( EXPLORE1 > 3999 )
     write("    博物學(natural_history)        ( 經驗值比例 = 150%, 上限 = 100 )");
     if ( EXPLORE1 > 1999 )
     write("    診斷(diagnose)                 ( 經驗值比例 = 120%, 上限 =  60 )"
           "    倫理學(ethics)                 ( 經驗值比例 = 130%, 上限 =  50 )");
     if ( EXPLORE1 > 999 )
     write("    交易(trading)                  ( 經驗值比例 = 150%, 上限 =  70 )"
           "    辯術(polemic)                  ( 經驗值比例 = 120%, 上限 =  50 )\n");
     return 1;
}    
