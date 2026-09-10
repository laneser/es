//#pragma save_binary

/*
// Author (??)
// Help added by Brian (1/28/92)
// Converted to mudlib 0.9.0 by Mobydick on 9/19/92
// Kill monster option added by Watcher on 2/19/93
// Watcher added vision check, 4/13/93

// The MudOS mudlib permits player killing by default. It is not hard to
// modify the mudlib to prevent player killing, or permit it only in special
// rooms such as arenas. Instructions for doing this are found in the file
// /doc/mudlib/player_killing.
// If you prevent player_killing you should probably prevent players from
// stealing from one another also, since fights start when the victim detetcts
// a theft.
*/

#include <mudlib.h>

inherit DAEMON;

// More fun. - Annihilator 12-08-93

string *start_fight = ({
	"%s喝道: 可惡的%s，看招！\n",
	"%s喝道: 該死的%s，下地獄去吧！\n",
	"%s喝道: 納命來，%s！\n",
	"%s喝道: 去死吧 !! %s !!\n"
});

int help();
string get_monster();

int cmd_kill(string str)
{
	object victim, venv, me;
	int i;

	if( str == "monster" ) str = get_monster();
	if( !str || str == "" ) return help();

	me = this_player();
	if( (int)me->query("hit_points")<=0 )
		return notify_fail("很抱歉，你已經死了。\n");

	str = lower_case(str);
	venv = environment(me);
	if( !venv )
		return notify_fail("你不能在一片虛無當中攻擊別人。\n");
 
	if( !me->query("vision") )
		return notify_fail("攻擊誰？你什麼也看不見！\n");
 
	victim = present(str, venv);
	if( !victim || !visible(victim, me) )
		return notify_fail("這裡沒有你想攻擊的對象。\n");

	if( !living(victim) )
		return notify_fail("看清楚，那不是值得攻擊的對象。\n");

	if ( victim->query("no_attack") ) {
		if( !member_group((string)me->query("name"), "admin") )
		return notify_fail("別輕舉妄動，這傢伙你不能殺就是不能殺。\n");
	}
	if( (int)victim->query("ghost")==1 )
		return notify_fail("這個可憐蟲已經死了，你還想怎樣？\n");

	if( victim == me )
		return notify_fail("殺你自己？你不會拼 suicide 嗎？\n");
 
	if( victim->query("linkdead") )
		return notify_fail("你不能趁人家斷線的時候幹這種事！\n");
 
 	if ( victim->query("user") ) {
	 	if( !member_group((string)me->query("name"), "admin") &&
 			(victim->query_level()<5 || me->query_level()<5) )
 		return notify_fail("在東方故事中五級以下的玩家不準 PK 和 PK 別人。\n");
	}
	i = me->kill_ob(victim);
	if( i==0 )
		write( "對！加油！加油！加油！\n");
	else {
		i = random( sizeof(start_fight) );
		write( 
			sprintf( start_fight[i],"你", victim->query("c_name") ));
		tell_room( environment(me), 
			sprintf( start_fight[i],
				me->query("c_name"), victim->query("c_name") ) ,
			me );
	}

	victim->set_heart_beat(1) ;
	return 1 ;
}

string get_monster()
{
	mixed *env;
 
	env = all_inventory( environment(this_player()) );
	if( !env || !sizeof(env) )  return 0;
 
	env = filter_array(env, "filter_npc", this_object());
	if( !env || !sizeof(env) )  return 0;

	return (string)env[0]->query("name");
}
 
int filter_npc(object obj)
{
	return (int)obj->query("npc");
}
 
int help()
{
		write(@HELP
指令格式: kill <怪物名稱>

殺npc或玩家。當開始後將無法取消指令，除非有一方死亡。
此外npc會記仇，有些甚至會追殺你。。
HELP
		);
	return 1;
}
/* EOF */
