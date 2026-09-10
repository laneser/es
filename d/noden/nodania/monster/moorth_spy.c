#include <mudlib.h>

inherit MONSTER;

void create()
{
   object weapon;

	::create();
	set_level(13);
   set_name( "Moorth Spy", "默爾斯間諜" );
   add( "id", ({ "spy" }) );
   set_short( "默爾斯間諜" );
	set_long(
         "他是默爾斯大軍(army)派出的間諜, 他正努力地刺探軍情(news)。\n"
	);
   set( "alignment", -500 );
	set_perm_stat("str",16);
	set_perm_stat("dex",15);
	set_skill("parry", 50);
   set_skill( "dodge", 60 );

	set( "race", "human" );
	set( "gender", "male" );
   set_natural_armor( 40, 10 );
   set( "pursuing", 1 );
   set( "moving", 1 );
   set( "speed", 10 );
   set( "patrol", ({ "east", "west", "west", "west", "west", "east",
          "north", "south", "east", "east" }) );

   wield_weapon( "/d/moorth/obj/shortsword" );

   set( "inquiry", ([
          "news" : "@@ask_news",
          "reward" : "@@ask_reward",
          "inform" : "@@ask_inform",
          "army" : "我們的大軍正準備進攻諾達尼亞城, 要命快閃吧!\n" 
        ]) );
}

int ask_news(object who)
{
   if( (int)who->query_level()<5 ) {
     write( "走開! 走開! 無名小卒別煩我!\n" );
     return 1;
   } else {
   tell_object( who, @LONG
嘿嘿嘿...沒錯! 我正在收集情報, 如果你能提供對我們有利的
情報(inform), 你將會得到很大的好處(reward)!
LONG
     );
     return 1;
   }
   return 1;
}

int ask_inform(object who)
{
   if( (int)who->query_level()<5 ) {
     write( "走開! 走開! 無名小卒別煩我!\n" );
     return 1;
   } else {
   tell_object( who, @LONG
我們的軍隊一直想進攻達尼亞城, 無奈那個守軍將領戴利佛
對我們的行動瞭如指掌, 要是他死掉就好了!
LONG
     );
     return 1;
   }
   return 1;
}

int ask_reward(object who)
{
   if( (int)who->query_level()<5 ) {
     write( "走開! 走開! 無名小卒別煩我!\n" );
     return 1;
     }

   if( who->query_temp("war_spy") ) {
   tell_object( who, @LONG
很好, 非常感謝你的幫助! 而且也高興看到你還活著!
這是當初講好的賞金.
[ 默爾斯間諜拿出一袋錢幣給你 ]
LONG
     );
   who->credit( "silver", 777 );
   who->delete_temp( "war_spy" );
   who->set_explore("noden#15");
   return 1;
   } else {
     write(
"如果那個將軍死去, 而你能在高塔上揮舞(brandish)他的佩劍\n"
"通知我軍的話, 我將給你一筆龐大的賞金! 不過...\n"
"我們的大軍是六親不認, 殺人不眨眼的噢!\n" );
     return 1;
     }
   return 1;
}
