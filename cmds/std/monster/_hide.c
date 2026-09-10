////#pragma save_binary
#include <mudlib.h>
#define in_msg ({ "你找到一個陰暗的角落躲了起來。\n","你躲到桌子的下面。\n",\
		"你開始偽裝成一座雕像。\n","你開始念 : 你看不到我 ... 你看不到我 ...\n",\
		"你把自己的眼睛蒙起來。\n","你貼在牆壁上，喃喃的念 : 我是壁花 ... 我是壁花 ...\n",\
		"你保持半蹲，假裝是一張椅子。\n","你趴在地上, 動也不動。\n" })
#define out_msg ({ "你舉起一支樹枝，假裝是一棵樹。\n","你在頭上插滿青草，假裝是草叢。\n",\
		"你蹲在地上，偽裝成一顆大石頭。\n","你躡手躡腳的躲到草叢裡。\n",\
		"你找到一個陰暗的角落躲了起來。\n","你開始念 : 你看不到我 ... 你看不到我 ...\n",\
		})

inherit DAEMON;

int hide_idle(object me,int succeed)
{
	me->add_temp("hide_score",succeed);
	if ( environment(me)->query("outside") ) 
		me->quick_message(out_msg[random(sizeof(out_msg))]);
	else
		me->quick_message(in_msg[random(sizeof(in_msg))]);
	return 1;
}

int check_hide(object me)
{
	int base,r,skill;
	object attacker,ob;

	if ( attacker = me->query_attacker()  ) {
		ob = attacker->query_attacker();
		if ( (string)ob->query("name") == (string) me->query("name") )
			return -100;
	}
// 只跟 skill 有關 ....
	skill = (int) me->query_skill("hide") + (int) me->query("thief_level/backstab")/2;
	return (random(skill));
}

int cmd_hide()
{
	int score;
	if ( (int)this_player()->query_temp("next_action") > time() )
		return notify_fail("你正在做其他事情 ...\n");
	write(set_color("你開始想辦法躲躲藏藏 ...\n","HIY"));
	score = check_hide(this_player());
	if ( score < random(40) )
	tell_room(environment(this_player()),
			sprintf("%s開始到處躲躲藏藏 ...\n",this_player()->query("c_name"))
			,this_player() );

	this_player()->set_temp("next_action",time()+2);
	this_player()->set_temp("hidding",1);
	call_out("hide_idle",2,this_player(),score);
	return 1;
}

int help()
{
	write (@HELP
Usage: hide

這個指令能使你利用各種地形地物來隱藏自己，使得四周的人不再對你
對你有戒心，如果成功的話，你將暫時從他們面前消失，直到你再次引
起他們的好奇心。如果你不怕附近的人笑你，多試幾次是很有可能成功
的，但是要小心別人先下手為強。

HELP
);
	return 1;
}
