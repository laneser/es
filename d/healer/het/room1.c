#include <mudlib.h>
#include <conditions.h>
#include "wang.h"
inherit ROOM;

void init()
{
	add_action("do_pick","pick");
}
void create()
{
 	::create();
        set_short("花圃");
	set_long(@LONG
走到這裡，讓你眼前一亮。這裡開滿了各種花，放眼望去，一片花海。陣陣花香，
讓你覺得彷佛身在仙境。紅的、黃的、白的、藍的、紫的甚至稀有的黑色的花，這裡
都可以看到。水桶，小鏟子，鋤頭等等工具四處散著，顯然這裡的花是有人細心照顧
的。南方不遠處隱隱約約有個茅屋。
LONG
);
	set("light", 1);
	set("exits",([
		"south" : WANG"room2" ,
		"east" : WANG"room7" ,
		"west" : "/d/eastland/forest/4,2.forest", 
	]));
	set("pre_exit_func", ([
	     "west" : "leaving",
	    ]));
	set("item_desc", ([
	     "flower"     : 
"這裡的花開的很漂亮，藍色的花(blue flower)更引起你的好奇心，想要看清楚些。\n",
	     "blue flower" : "一朵藍色的花，聞起來有股淡淡的香。想不想摘下來(pick) ?\n",
	     "red flower" : "一朵紅色的花，看起來很漂亮。想不想摘下來(pick) ?\n",
	    ]));

	set( "objects" ,([
	     "boy" : WANG_MOB"boy01"
	]));

	reset();
}


do_pick(string str)
{
	string *arg, color,item,tmp;
	object who;
        string whoname;


	if ( ! str ) 
		return notify_fail("你要摘什麼?\n");

	who = this_player();
	arg = explode(str," ");
	
	if ( sizeof(arg) < 2 )
		return notify_fail("你要摘什麼?\n");

	color = arg[0]; item = arg[1];
	if ( item != "flower" ) 
		return notify_fail("這裡沒有這種東西。\n");

	whoname = (string)who->query("c_name");

	switch ( color ) {
	   case "red" :
		tell_object(who,"你摘下一朵紅花，湊往鼻邊一聞，沒想到奇臭無比，一驚之下，隨手把它丟了。\n");
		tell_room(this_object(),
			sprintf("%s摘了一朵花，隨即把花丟掉。\n",whoname));
		break;
	   case "blue" :
		tell_object(who,
"你選了一朵最漂亮的花，輕輕的摘下來，但是不小心被旁邊的小刺扎到，有點麻麻的。\n");
		tell_room(this_object(),
			sprintf("%s摘了一朵花。\n",whoname));
		call_out("little_poison",8,who);
		break;
	   default :
		tell_object(who,"這花還沒開，換摘別的花吧。\n");
		break;
	}
	return 1;
}


int leaving()
{
object who;
	who = this_player();
	if ( (int) who->query_temp("kill_wang") == 0) 
		return 0;
	else { 
		tell_object(who,
"當你要離開這花圃時，一陣花香飄過來.. 你覺得很舒服.... \n"
"突然間你想到這邊是王藥師的花圃，但是已經來不及了!!\n"
		);
		(CONDITION_PREFIX + "simple_poison")->
			apply_effect(who,15,6);
		call_out("again",30,who);		
		who->delete_temp("kill_wang");
	}
	return 0;/* still can leave */
}

void little_poison(object who)
{
	tell_object(who,"你忽然手臂漸漸發麻... 剛剛的藍花原來是有毒的!!\n");
	(CONDITION_PREFIX + "slow") ->apply_effect(who,5,5);
}

void again(object who)
{
	tell_object(who,"你忽然一陣不舒服，原來王藥師的毒不只這樣...\n");
	(CONDITION_PREFIX + "weak") ->apply_effect(who,30,15);
	(CONDITION_PREFIX + "slow") ->apply_effect(who,30,15);

}
