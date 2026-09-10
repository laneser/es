//#pragma save_binary

// File: /cmds/std/_party.c
// written by Zeus @1993
// to be used in conjunction with
// my party daemon

#include <mudlib.h>
#include <daemons.h>

#define NAME(x) (string)x->query("name")
#define CAPNAME(x) (string)x->query("cap_name")
#define C_CAPNAME(x) (string)x->query("c_name")
#define LEADER(x) (string)x->query_temp("leader")
#define POSS(x) possessive((string)x->query("gender"))

inherit DAEMON;

int help();

int handle_form()
{
	if((LEADER(this_player())))
		return notify_fail( 
			"你已經是某個隊伍的成員了。\n");
	PARTY_D->form_party(this_player());
	return 1;
}

int handle_invite(string str)
{
	object ob;

	if(!(LEADER(this_player())))
		return notify_fail( 
			"你並沒有組織任何冒險隊伍。\n");
	if( (LEADER(this_player())) != (NAME(this_player())) )
		return notify_fail(
			"你並不是這個冒險隊伍的領袖。\n");
	ob = present(lower_case(str), environment(this_player()));
	if(!ob)
		return notify_fail( 
			"這個人並不在這裡。\n");
	PARTY_D->invite_member(this_player(), ob);
	return 1;
}

int handle_join(string str)
{
	object ob;

	if((LEADER(this_player())))
		return notify_fail(
			"你已經參加了一個冒險隊伍。\n");
	ob = present(lower_case(str), environment(this_player()));
	if(!ob)
		return notify_fail( 
			"這裡沒有這個人。\n");

	if(!(LEADER(ob)))
		return notify_fail( 
			C_CAPNAME(ob) + "並不屬於任何冒險隊伍。\n");
	if((LEADER(ob)) != (NAME(ob)))
		return notify_fail(
			C_CAPNAME(ob)+"並不是"+to_chinese(POSS(ob))+"冒險隊伍的領袖。\n");
	PARTY_D->add_member(ob, this_player());
	return 1;
}

int handle_leave()
{
	object ob;

	if(!(LEADER(this_player()))) {
		notify_fail("你並不屬於任何一個隊伍.\n");
		return 0;
	}
	if((LEADER(this_player())) == (NAME(this_player()))) {
		notify_fail("喂 ! 你是領袖耶 !! 有志氣一點好嗎？\n");
		return 0;
	}
	ob = find_living(lower_case(LEADER(this_player())));
	if(!ob) {
		notify_fail("你的領袖不見了，請跟巫師報告.\n");
		return 0;
	}
	PARTY_D->disband_member(ob, this_player(), 0);
	return 1;
}

int handle_remove(string str) {
	object ob;

	if(!(LEADER(this_player()))) {
		notify_fail("你不屬於任何隊伍.\n");
		return 0;
	}
	if((LEADER(this_player())) != (NAME(this_player()))) {
		notify_fail("你又不是領袖，不要亂來嘛 !!\n");
		return 0;
	}
	ob = find_living(lower_case(str));
	if(!ob) {
		notify_fail("嗯 ～ 有這個人嗎？\n");
		return 0;
	}
	if((LEADER(this_player())) != (LEADER(ob))) {
		notify_fail(CAPNAME(ob)+"不是你的隊友.\n");
		return 0;
	}
	PARTY_D->disband_member(this_player(), ob, 1);
	return 1;
}

int handle_disband() {
	if(!(LEADER(this_player()))) {
		notify_fail("你不屬於任何冒險隊伍.\n");
		return 0;
	}
	if((LEADER(this_player())) != (NAME(this_player()))) {
		notify_fail("你不是領袖，不要亂來好嗎？\n");
		return 0;
	}
	PARTY_D->disband_party(this_player());
	return 1;
}

int handle_members() {
	object ob;

	if(!(LEADER(this_player()))) {
		notify_fail("你不屬於任何隊伍.\n");
		return 0;
	}
	if((LEADER(this_player())) == (NAME(this_player()))) ob = this_player();
	else ob = find_living(lower_case(LEADER(this_player())));
	if(!ob) {	
		notify_fail("你的領袖不見了，請跟巫師報告.\n");
		return 0;
	}
	PARTY_D->party_list(ob);
	return 1;
}

int handle_leader(string str) {
	object ob;

	if(!(LEADER(this_player()))) {
		notify_fail("你不屬於任何隊伍.\n");
		return 0;
	}
	if((LEADER(this_player())) != (NAME(this_player()))) {
		notify_fail("怎麼？你想篡位嗎？\n");
		return 0;
	}
	ob = find_living(lower_case(str));
	if(!ob) {
		notify_fail("嗯 ～ 有這個人嗎？\n");
		return 0;
	}
	if((LEADER(this_player())) != (LEADER(ob))) {
		notify_fail(CAPNAME(ob)+"不是你的隊友.\n");
		return 0;
	}
	PARTY_D->change_leader(this_player(), ob);
	return 1;
}

int cmd_party(string str)
{
	string foo, fii;

	if(!str) {
		if((LEADER(this_player())))
			write("你是"+
				capitalize(LEADER(this_player()))+"的冒險隊伍的隊員.\n");
		else write("Usage: party <action> [<player>]\n");
		return 1;
	}
	if(sscanf(str, "%s %s", foo, fii) == 2) {
		switch(foo) {
			case "invite" : return handle_invite(fii); break;
			case "join" : return handle_join(fii); break;
			case "remove" : return handle_remove(fii); break;
//			case "leader" : return handle_leader(fii); break;
			default : return help();
		}
	} else if(sscanf(str, "%s", foo) == 1) {
		switch(foo) {
			case "form" : return handle_form(); break;
			case "leave" : return handle_leave(); break;
			case "disband" : return handle_disband(); break;
			case "members" : return handle_members(); break;
			default : return help();
		}
	}
	return help();
}

int help()
{
	write(@HELP
用法:
	party form             組建一個隊伍，發出指令者為隊伍首領。
	party join <player>    加入一個已建立的隊伍，前提是收到邀請。
	party leave            脫離隊伍。
	party members          查看自己隊伍的成員名單。
	party invite <player>  邀請某人加入你的隊伍。
	party remove <player>  踢某人出你的隊伍。
	party disband          解散隊伍，隊伍首領專用。

這個指令允許你和你的夥伴組織一個隊伍共同遊戲。
你可以先組建一個隊伍，然後對你的夥伴發出邀請，你的夥伴收到邀請後
有60秒時間考慮是否假如你的隊伍.
如果你死亡或退出遊戲，你就會自動退出隊伍，如果你是隊伍的首領，隊伍
將會被解散.
HELP
);
	return 1;
}
