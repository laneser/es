// Created by Kyoko.

#include <mudlib.h>
#include <gonfu.h>

inherit DAEMON ;

int gonfu_exists(string gonfu);

int help() ;

int cmd_enhant(string gonfu)
{
	int fp_cost, delay_time;
    object code;
    
	if( !gonfu ) return help();

	if( (int)this_player()->query("stop_attack")>0 )
		return notify_fail (can_read_chinese()?
			"( 你上一個動作還沒有完成，無法施展招式。 )\n":
			"( You are too busy to enhant a gonfu now. )\n"
		);
    if( this_player()->query_temp("no_enhant") ||
        this_player()->query("no_enhant") )
      return notify_fail( can_read_chinese() ?
        "你正準備使用招式時，竟然發現你突然忘記起手式了。\n" :
        "You forget how to enhant any gonfu!\n"
      );
    if( environment(this_player())->query_temp("no_enhant") ||
        environment(this_player())->query("no_enhant") )
      return notify_fail( can_read_chinese() ?
        "這裡不能使用任何招式。\n" :
        "You can not enhant any gonfu here!\n"
      );
	if( !(this_player()->query("gonfus/"+gonfu)) )
	  return notify_fail( can_read_chinese()?
		"你不會這種功夫。\n":
		"You don't know such a gonfu.\n"
	  );
	code = GONFU_D->find_gonfu( gonfu );
	if( !code )
		return notify_fail( can_read_chinese()?
			"沒有這種功夫 .... 請通知巫師或用 bug 指令報告招式名稱。\n":
			"No such gonfu .... please tell a wizard or report bug.\n"
		);
	fp_cost = (int)code->query_fp_cost();
	delay_time = (int)code->query_delay_time();
	if( !fp_cost || (int)this_player()->query("force_points") < fp_cost )
		return notify_fail( can_read_chinese()?
			"你的內力不夠！\n":
			"You don't have enough force points!\n"
		);
    if( (string)this_player()->query_temp("gonfu_now") == gonfu )
        return notify_fail( can_read_chinese()?
			"你已在施展這功夫了！\n":
			"You have enhanting this gonfu!\n"
		);
    this_player()->set_temp("gonfu_now", gonfu);
    this_player()->set_temp("gonfu_delay_time", delay_time);
	if( code->enhant() )
	  this_player()->add("force_points", -fp_cost );
	return 1;
}

int help()
{
	if( can_read_chinese() )
		write( @C_HELP
指令格式: enhant <招式名稱>

這個指令讓你用來施展招式。你可以用 gonfus 指令看你目前已經學會的招式列表。
C_HELP
		);
	else write ( @HELP
Usage:	enhant <gonfu name>

This command let you enhant gonfus. You can type "gonfus" to see the 
gonfus you have learned.
HELP
    );
    return 1;
}
