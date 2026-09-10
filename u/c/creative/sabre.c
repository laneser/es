//#pragma save_binary

#include <mudlib.h>
#include "knight.h"

inherit GUILD_OB;
inherit WEAPON;

void create()
{
	seteuid( getuid() );
	guild_ob::create();
	set_class_name("knight");
#include <compress_obj.h>
	set_name("sabre", "佩刀");
	set_short("黃金佩刀");
	set_long( @LONG
這是一把屬於諾頓騎士團成員的黃金佩刀，這把佩刀也許並不是最好的武器，
但是它代表騎士的榮譽與生命。你可以用 help sabre 得到有關這把佩刀的進
一步說明。
LONG
	);

	set( "unit", "把" );
	set( "weapon_class", "@@query_weapon_class" );
	set( "type", "longblade" );
	set( "min_damage", "@@query_min_damage" );
	set( "max_damage", "@@query_max_damage" );
	set( "wield_func", "wield_sabre" );
	set( "weight", 60 );
	set( "extra_look", "$N帶著一把象徵騎士的軍刀。\n");
}

void init()
{
	// Apply guild_ob checks
	guild_ob::init();

	add_action("help", "help");
	add_action("info", "info");
	add_action("do_knights", "knights");
	add_action("do_chat", "knight");
}

int query_weapon_class() { return 10; }
int query_min_damage() { return 5; }
int query_max_damage() { return 10; }

void wield_sabre()
{
	write("你將配刀從刀鞘中抽出來，向諾達尼亞王宮的方向行了一個軍禮。\n");
    tell_room( environment(this_player()),
		this_player()->query("c_name")+"抽出黃金配刀，行了一個漂亮的軍禮。\n",
		({ this_player()}) );
}

int do_knights()
{
	return guild_ob::list_guild_members();
}

// The guild channel
int do_chat(string arg)
{
	if( !arg )
		return notify_fail( 
			"你想對其它騎士說什麼？\n");

	return guild_ob::guild_line(arg);
}

int info(string arg)
{
	switch(arg) {
		case "history": cat( GUILD_DATA"c_kni_history" );
			break;
		case "commands": cat( GUILD_DATA"c_kni_commands" );
			break;
		case "topics":
		default: 
			cat ( GUILD_DATA"c_topics");
			break;
	}
	return 1;
}

int help(string arg)
{
	if( !arg || arg!="sabre" ) return 0;
	cat( GUILD_DATA"c_sabre");
	return 1;
}
