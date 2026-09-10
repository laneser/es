//#pragma save_binary
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit DAEMON;

int cmd_clot(string arg)
{
	object dest;
	int skill;
	mixed bleed;

	if( !arg || arg=="" || !(dest = present(arg, environment(this_player()))) )
		return notify_fail( "你要替誰止血？\n" ); 

	if( !living(dest) ) return notify_fail( "那個「東西」不會流血。\n" );

	if( dest->query("ghost") ) return notify_fail( 
		sprintf("太遲了 .... %s已經死了。\n" ,dest->query("c_name")));
        
        if( dest->query("no_clot") ) return notify_fail(
                sprintf("%s笑著對你說:謝謝你的好意, 不過我想有必要時, 我自己動手可能比較好。\n",dest->query("c_name") )
           );     
        
	if( dest->query_temp("clotted") ) return notify_fail( 
		 sprintf("%s的傷口已經止血處理過了。\n" ,dest->query("c_name")));

	if( !(bleed = dest->query("conditions/bleeding")) )
		return notify_fail( 
			sprintf("%s並沒有失血的情形。\n" ,dest->query("c_name")));

	skill = (int)this_player()->query_skill( "clotting");
	if( !skill ) return notify_fail( "你並沒有學過止血的技能。\n" );

	write( sprintf("你替%s的傷口進行止血 ....\n" ,dest->query("c_name")));
        if (dest !=this_player())
	tell_object( dest, 
		sprintf("%s替你的傷口止血 .... 你覺得好多了！\n" ,this_player()->query("c_name")));
	tell_room( environment(this_player()), 
		sprintf("%s替%s的傷口止血。\n",
			this_player()->query("c_name"),dest->query("c_name")),
		({ this_player(), dest }) );
	if( dest!=this_player() )
		this_player()->add( "alignment", 25 );
	if( skill/2 + random(skill/2) > bleed[1] * bleed[2] ) {
		this_player()->receive_experience( skill );
		(CONDITION_PREFIX + "bleeding")->remove_effect( dest );
	} else {
		bleed[2] /= 2;
		dest->set( "conditions/bleeding", bleed );
		this_player()->receive_experience( skill/2 );
	}
	dest->set_temp("clotted", 1 );
	call_out( "remove_clotted", 120, dest );
    return 1;
}

void remove_clotted(object player)
{
	if( player ) player->set_temp("clotted", 0);
}

int help()
{
    write(
    @C_HELP
指令格式: clot <某人>

這個指令讓你替某個人物( 或 NPC )的傷口止血，有關止血的細節與限制請參
考 help clotting。
C_HELP
	);
    return 1;
}
