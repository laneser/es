#include <mudlib.h>

inherit DAEMON;

int cmd_aid(string arg)
{
	object dest;
	int hp, max_hp, skill, chinese_mode;

	chinese_mode = can_read_chinese();
	if( !arg || arg=="" || !(dest = present(arg, environment(this_player()))) )
		return notify_fail( "你要對誰施行急救？\n");

	if( !living(dest) ) return notify_fail("那個「東西」不需要急救。\n");

//	if( dest==this_player() ) return notify_fail( chinese_mode?
//		"你不能對自己施行急救。\n": "You can't aid yourself.\n" );

	if( dest->query("ghost") ) return notify_fail(
		"太遲了 .... "+dest->query("c_name")+"已經死了。\n");

	if( dest->query_temp("aided") ) return notify_fail(
		dest->query("c_name") + "已經被急救過了。\n");

	hp = (int)dest->query( "hit_points" );
	max_hp = (int)dest->query( "max_hp" );
	if( hp==max_hp ) return notify_fail(
		dest->query("c_name") + "並沒有受傷。\n" );

	if( hp > max_hp/6 ) return notify_fail(
		dest->query("c_name") + "的傷勢還沒有嚴重到需要急救的地步。\n" );

	skill = (int)this_player()->query_skill( "first-aid");
	if( !skill ) return notify_fail("你並沒有學過急救的技能。\n");

	write("你對" + dest->query("c_name") + "進行急救 ....\n");
	tell_object( dest, this_player()->query("c_name") + "對你進行急救 .... 你覺得好多了！\n");
	tell_room( environment(this_player()), this_player()->query("c_name") + "對" + dest->query("c_name") + "進行急救 ....\n",
		({ this_player(), dest }) );
	if( dest!=this_player() ) this_player()->add( "alignment", 25 );
	dest->receive_healing( skill/2 + random(skill/2) );
	dest->set_temp( "aided", 1 );
	this_player()->receive_experience( skill );
	call_out( "remove_aided", 300, dest );
    return 1;
}

void remove_aided(object player)
{
	if( player ) player->set_temp("aided", 0);
}

int help()
{
    write(can_read_chinese()?
    @C_HELP
指令格式: aid <某人>

這個指令讓你對某個人物( 或 NPC )施行急救，有關急救的細節與限制請參
考 help first-aid。
C_HELP
    :@HELP
Usage: aid <someone>

This command enables you to perform first aid to another player or
NPC. For more information about first aid, see help first_aid.
HELP
	);
    return 1;
}
