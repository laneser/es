//#pragma save_binary

#include <mudlib.h>
#include "scholar.h"

inherit GUILD_OB;
inherit OBJECT;

void create()
{
	seteuid( getuid() );
	guild_ob::create();
	set_class_name("scholar");
#include <compress_obj.h>
	set_name("jade mark", "玉符");
	add( "id", ({ "mark", "jade" }) );
	set_short("玉符");
	set_long( @LONG
這是一塊晶瑩剔透的美玉琢磨而成的玉符，自古以來的文人書生都喜歡
配戴一塊美玉以代表自己高尚的人格，就像玉一樣完美無暇，這塊玉是
若嵐城舞墨軒主人卞大夫的門下食客所配戴的，你可以用 help jade
得到有關書生公會的一些資料。
LONG
	);

	set( "unit", "塊" );
	set( "weight", 1 );
	set( "extra_look", "$N看起來溫文儒雅，頗有書卷氣息，腰間配著一塊晶瑩剔透的美玉。\n");
}

void init()
{
	// Apply guild_ob checks
	guild_ob::init();

	add_action("help", "help");
	add_action("info", "info");
	add_action("do_scholars", "scholars");
	add_action("do_chat", "scholar");
}

int do_scholars()
{
	return guild_ob::list_guild_members();
}

// The guild channel
int do_chat(string arg)
{
	if( !arg )
		return notify_fail("你想對其它書生說什麼？\n");
	return guild_ob::guild_line(arg);
}

int info(string arg)
{
	switch(arg) {
		case "commands":cat( GUILD_DATA"c_scholar_commands" );
		    break;
		case "gonfus":cat( GUILD_DATA"c_scholar_gonfus" );
		    break;     		
                case "history":cat( GUILD_DATA"c_scholar_history" );
		    break;
		default: 
			cat( GUILD_DATA"c_topics" );
			break;
	}
	return 1;
}

int help(string arg)
{
	if( !arg || arg!="jade" ) return 0;
	cat(GUILD_DATA"c_jade_mark");

	return 1;
}
