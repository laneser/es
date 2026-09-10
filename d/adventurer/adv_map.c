//#pragma save_binary

#include <mudlib.h>
#include "adventurer.h"

inherit GUILD_OB;
inherit MAP;
inherit OBJECT;

void create()
{
	guild_ob::create();
	seteuid(getuid());
	set_class_name("adventurer");
	set_size( 7, 7 );
#include <compress_obj.h>
	set_name("map", "地圖");
	set_short("冒險專用地圖");
	set_long(@LONG
這是一張十分著名的冒險者專用地圖，由一位當年發現通往東方大國
的偉大冒險者所繪製而成。對年青的冒險者可以提供很大的幫助，請
參閱 help map 以獲得進一步的說明。
LONG
	);

	set( "unit", "張" );
	set( "weight", 5 );
	set( "extra_look", "$N帶著冒險者專用的魔法地圖。\n");
}

void init()
{
	// Apply guild_ob checks
	guild_ob::init();

	// Apply map functions
	std_map::init();
	
	add_action("help", "help");
	add_action("info", "info");
	add_action("do_check", "check" );
	add_action("do_fellows", "fellows");
	add_action("do_chat", "adv");
}

int do_check(string str)
{
	object dest;
	int my_level, dest_level;

	if( !str || str=="" || !(dest= present(str, environment(this_player()))) )
		return notify_fail("指令格式: check <怪物>\n");
	my_level = (int)this_player()->query_level();
	dest_level = (int)dest->query_level();
	if( my_level < dest_level ) write("對方的等級比你高。\n");
	if( my_level == dest_level ) write("對方和你同等級。\n");
	if( my_level > dest_level ) write("對方的等級比你低。\n");
	return 1;
}

int do_fellows()
{
	return guild_ob::list_guild_members();
}

// The guild channel
int do_chat(string arg)
{
	if( !arg )
		return notify_fail("你想對其它冒險者說什麼？\n");
	return guild_ob::guild_line(arg);
}

int info(string arg)
{
	switch(arg) {
		case "history": cat( GUILD_DATA+"c_adv_history" );
			break;
	    case "commands": cat( GUILD_DATA+"c_adv_commands" );
			break;
		case "topics":
		default: 
write( @C_TOPICS
冒險者公會是一個屬於所有人的公會，你可以用 info 指令取得有關以下主題的資
訊:
    history    - 有關冒險者公會的歷史。
    commands   - 有關冒險者能使用的特殊指令。
    
C_TOPICS
			);
			break;
	}
	return 1;
}

int help(string arg)
{
	if( !arg || arg!="map" ) return 0;
	cat(GUILD_DATA+"c_adv_map");
	return 1;
}
