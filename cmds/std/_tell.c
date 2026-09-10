//#pragma save_binary

//	File	:  /cmds/std/_tell.c
//	Author	:  Various people (See tell daemon)
//
//	Mudlib tell command.  Also allows intermud-tells.
 
#include <net/daemons.h>
#include <mudlib.h>

inherit DAEMON;

#define SYNTAX "指令格式: tell <某人> <訊息>\n"

/* If you change this, please change it also in /adm/daemons/ts.c */
#define NH "%s並沒有在線上。\n"
 
int cmd_tell(string str)
{
	string tell_msg, who, msg, target, mud;
	object ob, act_ob;
	int tp;

	act_ob = previous_object();

	if( !str || sscanf( str, "%s %s", who, msg ) != 2 )
		return notify_fail( SYNTAX );

	notify_fail(sprintf(NH, capitalize(who)));

	if( sscanf(who, "%s@%s", target, mud) == 2 ) {
		write( TS_D->remote_tell(act_ob, target, mud, msg) );
		return 1;
	}

	who = lower_case(who);
	ob = find_player(who);

	if( ob && !userp(ob) && !ob->id(who) && !wizardp(act_ob) ) 
		return 0;

	if( !ob ) {
		if( ob = find_living(who) ) {
				tell_object(ob, sprintf("%s告訴你: %s\n",
					act_ob->query("c_name"), msg) );
				printf("你告訴%s(%s): %s",
					ob->query("c_name"), capitalize(who), msg);
			ob->set("reply", act_ob->link_data("name"));
			return 1;
		}
		return 0;
	}
	if (!userp(act_ob)) {
		tell_object(ob, sprintf("%s告訴你: %s\n",
				act_ob->query("c_name"), msg) );
		return 1;
	}	

	write( TS_D->tell_user(act_ob->link_data("name"), 0, who, msg) );

	return 1;
}

int help()
{

	write( SYNTAX + "\n" +
                "這指令可以將信息傳給特定的一個用戶或npc。\n");

	return 1;
}
