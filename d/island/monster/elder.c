//#include "../island.h"
#include <mudlib.h>
inherit MONSTER;

void create()
{
	
	::create();
	set_level(1);
	set_name( "Daemon Elder Ivan","魔族長老 伊凡" );
	add ("id", ({ "daemon", "elder", "ivan", }) );
	set_short( "魔族長老 伊凡" );
	set_long(@LONG
他是魔族派在村裡的代表，此外他還負責訓練魔族戰士的事，你可以問問
他有關訓練的事(train)。	
LONG
	);

        set( "gender", "male" );
        set( "race", "daemon" );
        set( "unit", "個" );
	set_perm_stat( "dex", 1 );
	set_perm_stat( "str", 1 );
	set_perm_stat( "int", 1 );
	set_perm_stat( "con", 1 );
	set_perm_stat( "pie", 1 );
	set_perm_stat( "kar", 1 );
	set("no_attack",1);
	set("no_steal",1);
        set ("weight", 300);
        set( "inquiry", ([
         "train" : "@@ask_train" ,
         "drill" : "@@ask_drill"
           ]) );
}

//void init()
//{
//     ::init();
//     add_action("to_comfort","comfort");
//}

void ask_train(object who)
{ 
  tell_object(who,"伊凡偷偷告訴你說：「關於訓練的事，我們基本上是希望訓練一批中間份子，\n");
  tell_object(who,"  所以基礎太差的人我是不收的，但是相對的你要是太強，我希望你不要妨礙\n");
  tell_object(who,"  後進的訓練，要是確實想訓練的話，可以問我有關受訓的事(drill)。」\n");
  return;     
}
void ask_drill(object who)
{ 
  int check;
  if((check=who->query_level())>15)
  { tell_object(who,"伊凡告訴你：「我想你已經可以自立了，孩子，多出去逛逛吧。」\n"); }
  else if(check<7)
  {  tell_object(who,"伊凡告訴你：「你的基礎不足，我怕你會在訓練的地方掛點，先到大草原練練吧。」\n"); }
  else
  {
    tell_object(who,"Bmp走到你面前說:xixi,雖然你達到了要求，但....這個功能還沒有開放，\n");
    tell_object(who,"你再等等，或催催負責這裡的wizard吧。    祝你走運。\n");
//  看下文，原來這個功能還未有，我先把他原來的wizard name //掉。
//  tell_object(who,"奧丁走到你面前說：「我最近期末考，所以暫時不能寫完，\n");
//  tell_object(who,"我的構想是寫一個給 7到15及練功的地方，完成了一定會告\n");
//  tell_object(who,"訴大家的。」\n");
  }
  return;
}  
