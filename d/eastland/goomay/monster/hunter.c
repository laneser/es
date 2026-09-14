#include "../goomay.h"

inherit MONSTER;

void create()
{

	::create();
	set_level(12);
	set_name( "hunter", "獵人阿三" );
	set_short( "獵人阿三" );
	set("long","@@query_c_long");
	set( "gender", "male" );
	set( "race", "orc" );
	set( "no_attack",1);
	set("inquiry",([ "health" : "@@ask_health" ]) );
}
void ask_health()
{
if( (int)this_player()->query_quest_level("Goddess_statue") < 2 )
	tell_object(this_player(),
	"獵人阿三感激地道 ： 謝謝你，我覺得好多了，請問你有找到我弟弟小四嗎？\n"
	"他在段家礦場工作，你問問守衛就知道了。\n");
else
	tell_object(this_player(),
	"獵人阿三爽朗地笑道 : 謝謝你 ! 我已經好了，小四也回來了，真不知道該怎麼感謝你 !!\n");
	return ;
}

string query_c_long()
{
if( (int)this_player()->query_quest_level("Goddess_statue") ){
    set("hit_points",this_object()->query("max_hp"));
    return "你看到一個健康(health)快樂的獵人，他有著古銅色的皮膚和令人信賴的眼神。\n"
     "他是山野的英豪 !! 如果你有任何需要，可以直接找他幫忙。\n";
  }
 else
  {
   set("hit_points",1);
   return "你看到一個病的奄奄一息的可憐人，原本古銅色的皮膚現在都成了死灰色，\n"+
     "如果再沒有人為這個神智不清的人去請醫生，恐怕他撐不了多久。\n";
  }
}

int accept_item(object me,object item)
{

     if ((string) item->query("name") !="pack of herbs" || 
         (int)this_player()->query_quest_level("Goddess_statue")>0 ) {
     tell_object(me,
        "獵人阿三苦笑著搖搖頭：「謝謝 !! 我不需要這東西 !!」\n");
        command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
	}
     tell_object(me,
"你把藥包交給重病的獵人，並且幫他煎好了藥餵他，吃了藥以後的阿三果然精神\n"
"好多了，虛弱的他掙扎著說：「我有一個弟弟，在段家的鐵礦坑工作，可否請您\n"
"替我把他叫回來 !! 謝謝 !! 你只要跟礦場守衛說要找"+
set_color("小四","HIY")+"就可以了 !! 」\n\n"
"看到他好多了，你覺得很欣慰 !! "+set_color("[ 得到 1500 點經驗 ]","HIC")+"\n"
		 );
	item->remove();
	this_player()->finish_quest( "Goddess_statue", 1 );
	me->gain_experience(1500);
        return 1;
}
