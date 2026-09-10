// cut_tail.c
// The guild token of the WKA's social guild.
// Created by Kyoko 4-7-94.

#include <mudlib.h>
inherit SOCIAL_GUILD_OB;
inherit WEAPON;
mapping levels = ([]);

void create()
{
	seteuid( getuid() );
	social_guild_ob::create();
	set_name("cut-tail knife", "割狼尾巴小刀");
	set_short("cut-tail knife", "割狼尾巴小刀");
	add( "id", ({ "knife", }) );
	set_long(
"This is a very sharp knife,made for cutting color-wolves tail.\n" ,
"這是一把十分鋒利的小刀,專門用來割(cut)色狼尾巴的.同時這也是屠狼\n"
"俱樂部的信物。欲查看如何割狼尾巴請用(help_cut)指令。\n"
	);
	
	set_social_class_name("WKA");
	set( "unit", "把" );
	set( "weapon_class", 1 );
	set( "type", "dagger" );
	set( "min_damage", 1 );
	set( "max_damage", 2 );
	set( "weight", 10 );
	set( "extra_look", "$N is a member of the WKA.\n");
	set( "c_extra_look", "$N帶著一把割狼尾巴小刀。\n");
}

void init()
{
	// Apply guild_ob checks
	social_guild_ob::init();
	//guild_ob::init();

	add_action("help", "help");
	add_action("do_WKAS", "WKAS");
	add_action("do_chat", "chat");
}

int do_WKAS()
{
	object *usr;
	int chinese_mode, i;

	chinese_mode = can_read_chinese();
	usr = filter_array( users(), "filter_knight", this_object() );
  	usr = sort_array( usr, "sort_usrs", this_object() );
	if( sizeof(usr) ) {
	    i=sizeof(usr);
	    write( chinese_mode ?
             "目前共有 " + i + " 位騎士連線中:\n"
			 "==================================\n":
			 "There are " + i + " knight(s) connected currently:\n"
			 "==================================================\n" );
		while(i--) {
			printf( "[ %2d ] %s\n", usr[i]->query_level(),
			usr[i]->query(chinese_mode?"c_short":"short") );
		}
	} else { 
		write( chinese_mode?
			"似乎沒有任何騎士公會的成員在線上....。\n":
			"There seems no any knights on now.\n"
		);
	}
	return 1;
}

int sort_usrs( object u1, object u2 )
{
        return (int)levels[u1] - (int)levels[u2];
}

int filter_knight( object plr )
{
        string name;
        if( (string)plr->query("class")=="knight" && visible(plr,this_player()) ) {
          levels[plr] = (int)plr->query_level();
          if( !levels[plr] || levels[plr] == 0 ) return 0;
          return 1;
        }
        return 0;
}

// The guild channel
int do_chat(string arg)
{
	object *usr;
	int chinese_mode, i;

	chinese_mode = can_read_chinese();
	if( !arg )
		return notify_fail( chinese_mode?
			"你想對其它騎士說什麼？\n":
			"What do you like to say to other knights?\n"
		);
	usr = filter_array( users(), "filter_knight", this_object() );
	if( sizeof(usr) ) {
		i = sizeof(usr);
		while(i--) {
			message( "guild_line", sprintf( can_read_chinese( usr[i] )?
			"[騎士] %s: %s\n": "[Knight] %s: %s\n",
			this_player()->query( can_read_chinese( usr[i] )? "c_cap_name": "cap_name" ),
			arg ), usr[i] );
		}
	}
	return 1;
}

int help(string arg)
{
	if( !arg || arg!="sabre" ) return 0;
	write( can_read_chinese()? @C_HELP
這把配刀是騎士榮譽的象徵，只要你帶著這把配刀，你就有以下幾個額外的指令:

    info <主題>    : 查詢和騎士公會有關的一些常識，你可以用 info topics 列出
                     所有的主題。
    knights        : 列出目前在線上的所有騎士。
    chat           : 使用騎士公會的專用頻道和其他騎士交談。

C_HELP
	:@HELP
The following commands are provided by the golden sabre:

    info <topic>    : Show information about Knight Guild, type 'info topics'
                      for a list of topics.
    knights         : List all knights on-line.
    chat            : Talk on knight channel
  
HELP
	);
	return 1;
}

