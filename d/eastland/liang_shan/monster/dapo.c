#include "mudlib.h"
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(15);
	set_name("Grandmother Da", "達婆婆");
	add ("id", ({ "da", "grandmother" }) );
	set_short("達婆婆");
	set_long(
		"你看到一個年老的老婆婆，躺在床上呻吟，乍看之下好像是\n"
		"病的奄奄一息的樣子，但仔細看看，卻好像沒有病的很重。\n");
	set_perm_stat("dex", 10);
	set_perm_stat("kar", 17);
	set_perm_stat("str", 13);
        set( "chat_chance",20);  
        set("chat_output",({"老婆婆不停的發出呻吟.......嗯.....唔.....\n"}));
	set_skill( "dodge", 30 );
	set( "max_hp", 380 );
	set( "hit_points", 380 );
	set( "gender", "female" );
	set( "race", "beholder" );
	set( "alignment", 100 );
	set( "tactic_func", "become_weak" );
	set_natural_armor( 35, 20 );
	set_natural_weapon( 34, 15, 20 );
	set( "forgetful", 1 );
	set( "time_to_heal", 5 );
        set( "inquiry", ([
              "sick" : "@@ask_sick",
              "food" : "@@ask_food"
              ]));
}
string c_call(object who)
{
	if ((string)who->query("gender") == "female")
	return (!who->query("spouse")) ? "妹妹" : "太太" ;
	else
	return (!who->query("spouse")) ? "弟弟" : "先生" ;
}
void ask_sick()
{
write (
"達婆婆嘆了一口氣，說道: 我是生病了...\n");
return ;
}

void ask_food()
{
write (
"達婆婆說道: 喔，這位" + c_call(this_player()) +"，你問我喜歡吃什麼嗎??\n"
"住在魚村當然喜歡吃魚啦，只是我病的快葛屁了，那有心情吃呢??\n");
return ;
}

int become_weak()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    tell_room( environment(this_object()),
            "\n達婆婆叫道: 連生病的人都要欺負....你不怕被傳染嗎??\n"
            "你聽完達婆婆的話，覺得身體有些不對勁.......\n\n",
		this_object() );
	(CONDITION_PREFIX + "weak")->apply_effect( victim, 2, 12 );
	return 1;
}

int accept_item(object me,object item)
{
	string name;
	name=(string)item->query("name");
     if ( !name || (name!="fish meat") ) return 1;
{
     tell_object(me,
@MEAT
達婆婆接過黃金夢幻鯉魚的肉，不禁淚流滿面....

沒想到湖裡還有黃金夢幻鯉魚，幾十年沒有嘗過它鮮美的滋味了...

MEAT
	);
//      command("eat meat");
        item->remove();
     tell_object(me,
@HAHA
達婆婆抬頭看著你，說道: 為了再吃到黃金夢幻鯉魚，我怎麼能夠躺在這
兒等死呢? 說完: 從屋角的箱子裡拿出釣竿，準備要去釣魚....

不管怎麼說，幫助達婆婆重拾健康，你感到無比的快樂。
HAHA
	);
	  if( (int)this_player()->query_quest_level("A_da")<1 ) {
		write("你完成了達婆婆任務，得到了7000點經驗值\n");
		this_player()->finish_quest( "A_da", 1 );
		this_player()->gain_experience(7000);
	   }
		                           return 1;
}
}
