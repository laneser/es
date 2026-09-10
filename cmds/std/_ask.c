//#pragma save_binary

#include <mudlib.h>
inherit DAEMON;

int cmd_ask(string str)
{
	string mon_name, subject, func;
	object mon_obj;
	mapping cmd_map;

	if (!str)
		return notify_fail(
			"要問非玩者人物問題，請用 \"ask <誰> about <關鍵字>\"。\n");

	if (sscanf(str, "%s about %s", mon_name, subject) != 2)
		return notify_fail( 
			"要問非玩者人物問題，請用 \"ask <誰> about <關鍵字>\"。\n");

	mon_name = lower_case(mon_name);

	if( !(mon_obj= present(mon_name, environment(this_player()))) )
		return notify_fail( 
			"你要問的對象並不在這裡。\n");

	if (mon_obj->query("user")) {
		write( 
			"你向"+ mon_obj->query("c_name") + "詢問有關 "+subject+" 的事。\n");

		tell_object( mon_obj,
			this_player()->query("c_name")+"問你: 知不知道有關 "+subject+" 的消息？\n");
		return 1 ;
	}

	cmd_map = ([ ]);
	cmd_map = mon_obj->query("inquiry");

	if (sizeof(cmd_map)==0) {
		write( 
			mon_obj->query("c_name")+"對你的問題沒有任何反應....。\n");
		return 1 ;
	}
	if( undefinedp(cmd_map[subject]) ) {
		tell_room(environment(this_player()), 
			this_player()-> query("c_name") + "向" + mon_obj->query("c_name")
			+ "打聽有關 " + subject + " 的消息。\n",
			this_player() );
		tell_room( environment(this_player()), 
			mon_obj->query("c_name") + "搖搖頭，說道: " + "我不知道....。\n" );
	} else {
		tell_room(environment(this_player()), 
			this_player()-> query("c_name") + "向" + mon_obj->query("c_name")
			+ "打聽有關 " + subject + " 的消息。\n",
			this_player() );
		if( stringp(cmd_map[subject]) && sscanf( cmd_map[subject], "@@%s", func )==1 )
			call_other( mon_obj, func, this_player() );
		else {
			if( pointerp(cmd_map[subject]) )
				tell_room(environment(this_player()), 
					mon_obj->query("c_name") + "說道: " + cmd_map[subject][0] + "\n",
					mon_obj );
			else
				tell_room(environment(this_player()), 
					mon_obj->query("c_name") + "說道: " + cmd_map[subject] + "\n",
					mon_obj );
		}
	}
	return 1;
}
int help()
{
	write(@HELP
使用格式: ask <生物名> about <事物>

用於以npc交談、解謎的標準指令.
不過有些場合仍要先用say或tell指令對npc說關鍵字才能觸發情節.

HELP
);
	return 1;
}