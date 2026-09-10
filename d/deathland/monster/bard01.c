
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	seteuid(getuid());
	set_level(5);
	set_name( "bard lucksis", "流浪詩人拉克西絲" );
	add("id",({"bard","lucksis"}));
	set_short( "a bard lucksis", "流浪詩人拉克西絲" );
	set_long(
		"A bard named lucksis. she has already searched many \n"
		"years to find her lover.\n",@DESC
一個流浪詩人拉克西絲,在向惡神 Yang 問過自己的命運後,就開始她千里
漂泊的旅程尋找她命運中的愛人(lover)
DESC
	);
	set("alignment",500);
	set_perm_stat( "dex", 7 );
	set_perm_stat( "str", 5 );
	set_perm_stat( "int", 8 );
	set_perm_stat( "con", 10 );
	set_perm_stat( "piety", 17);
	set_perm_stat( "karma", 10);	
	set ("max_hp", 125);
	set ("max_sp", 0);
	set ("hit_points", 125);
	set ("spell_points", 0);
	set( "race", "human" );
	set( "gender", "female" );
	set_skill("unarmed",30);
	// set( "no_attack", 1 );
	set( "inquiry", ([
		"lover" : "@@ask_lover",
		"romance" : "@@ask_romance",
		"desyer" : "@@ask_man",
	   	"ebbruce": "@@ask_man",
		"lawierda": "@@ask_man",
		"dalifore": "@@ask_man",
	]) );
}

void init()
{
   ::init();
   add_action("suggest_who","suggest");
}

void ask_man(object who)
{
     if (!(who->query_temp("lucksis_quest"))||(int)(who->query_temp("lucksis_quest/ask"))<2)
        tell_object(who,"拉克希絲對你不理不睬.\n"); 
     else if( (int)(who->query_temp("lucksis_quest/ask") )==2 ) 
        tell_object(who,"或許他是我命運中的伴侶\n");
     else   
        tell_object(who,"我已經決定獻身給 Yang 了,請你幫助我\n");
     return;     
}

void ask_romance(object who)
{
     if ( !(who->query_temp("lucksis_quest")) ||(int)(who->query_temp("lucksis_quest/ask"))==0 )
        tell_object(who,"拉克希絲說道:你覺得問人隱私是一件有趣的事嗎?\n");
     else 
       {
         tell_object(who,@MSG1
拉克希絲向你小聲地說道:在我旅行的數年間,我的愛情故事幾乎是一片空
白,但是有幾個高尚的紳士曾經溫文有禮地與我共同經歷過一段冒險,他們
的名字分別是蘭耳達(Lawierda),底斯宜爾(Desyer),艾柏魯斯(Ebbruce)及
戴利佛(Dalifore),當時我基於禮貌,並沒有回應他們的愛意,但是流浪了這
麼多年,我已經疲倦了,希望你能幫助我,一個女孩子家總是不好意思開口 ,
麻煩你幫我問一問他們的意思,然後給我一個建議(suggest),誰將是我最好
的伴侶,謝謝你.
MSG1
         );
         who->set_temp("lucksis_quest/ask",2);
       }
     return;   
}
void ask_lover(object who)
{
     if ( !(who->query_temp("lucksis_quest")) )
        {
        tell_object(who,@MSG2
拉克希絲說道:在我旅行的數年間,我見過各式各樣的人.
而我命運中的愛人........

拉克希絲長嘆一聲,低頭不語,似乎有什麼話要說的樣子.
MSG2
          );
        who->set_temp("lucksis_quest",(["ask":0,
                                      "desyer":0,
                                      "lawierda":0,
                                      "ebbruce":0,
                                      "dalifore":0,
                                        ]) );
        call_out("tellyou",10,who);
        return;
        }  
     else  /* if ( (int)( who->query_temp("lucksis_quest/ask") ) !=2 ) */
        {
          tell_object(who,@MSG3
拉克希絲說道:在我旅行的數年間,我見過各式各樣的人.
而我命運中的愛人........

拉克希絲長嘆一聲,低頭不語,似乎有什麼話要說的樣子.
MSG3
          );
        }
     
     return;
} 


int tellyou(object who)
{
    if ((int)(who->query_temp("lucksis_quest/ask"))==0) {
      tell_object(who,@MSG4
拉克希絲(Lucksis)告訴你:或許你能幫助我解決這個難題
拉克希絲(Lucksis)告訴你:回來我這裡,我將告訴你關於我的羅曼史(romance)
MSG4
               );
      who->set_temp("lucksis_quest/ask",1);
      }
    return 1;
}

int suggest_who(string str)
{
    object who;
    int *aaa,i,j;
    mapping x=(["desyer" :"底斯宜爾 ","lawierda":"蘭耳達 ",
                "ebbruce":"艾柏魯斯 ","dalifore":"戴利佛 "]);
    who=this_player();
    if (!(who->query_temp("lucksis_quest"))|| (int)(who->query_temp("lucksis_quest/ask"))!=2 )
      {
       tell_object(who,"拉克希絲瞪你一眼說:別吵我\n"); 
      }  
    else if ( (int)( who->query_temp("lucksis_quest/ask") )==2)  
        {
          aaa=values(who->query_temp("lucksis_quest"));
          for (i=0,j=0;i<sizeof(aaa);i++) j+=aaa[i];
          if ( j==sizeof(aaa)+1 )  
             {
             tell_object(who,@MSG5
當你幫我去問他們的意見時,我自己想了許多,其實一個人的生
活也不算太壞,而且經過了這麼多年的風風雨雨,我已經看開了.
我打算服侍 Yang,到冥界去當修女 
請你幫助我最後一次,送我到冥界去,謝謝你.
MSG5
              );
             who->set_temp("lucksis_quest/ask",3);
             }  
          else 
            
            tell_object(who,"拉克西絲說:麻煩你再去問問"+
            ( (int)(who->query_temp("lucksis_quest/desyer"))==0 ? x["desyer"] : ""  )   +
            ( (int)(who->query_temp("lucksis_quest/lawierda"))==0 ? x["lawierda"] :""  )+           
            ( (int)(who->query_temp("lucksis_quest/ebbruce"))==0 ? x["ebbruce"] : ""   )+
            ( (int)(who->query_temp("lucksis_quest/dalifore"))==0 ? x["dalifore"] : "" )+
            "\n然後再給我建議,謝謝你\n"
            );
         }
         
    return 1;
}

void die()
{
   object killer;
   
   killer = query("last_attacker");
   if ( !(killer->query_temp("lucksis_quest")) || (int)(killer->query_temp("lucksis_quest/ask"))!=3)
     tell_room(environment(),
        sprintf("拉克希絲說: Yang 將詛咒%s.\n拉克希絲倒地而不甘心的死去\n",killer->query("name") )
              );
   else
     {
        if ( (int)killer -> query_quest_level("lucksis_lover") < 1 )
          {
          tell_object(killer,sprintf("拉克希絲說:謝謝你超渡我,%s\n",killer->query("name")));
          killer->finish_quest("lucksis_lover",1);
          killer->delete_temp("lucksis_quest");
          killer->gain_experience(3000);
          this_player()->set_explore( "deathland#39" );
          tell_object(killer,"\n你完成了拉克希絲的命運,獲得了3000點經驗值.\n");
          //write_file("/log/lucksis_quest.log",
          //  sprintf("**%s finished the quests in %s.\n",
          //           killer->query("name"),ctime( time() ) ) );
          }
        else {
          tell_object(killer,sprintf("拉克希絲說:謝謝你再度超渡我,%s\n",killer->query("name")));
          this_player()->set_explore( "deathland#39" );
        }
     }  
   ::die(1);
}
