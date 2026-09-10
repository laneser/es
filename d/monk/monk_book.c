//#pragma save_binary

// monk_book.c
// The guild token of the monk's guild.
// Sub Usage: The spell book of mages, containing most spells one can find
//            in the mud. But not all spells it can remember.
// Created by Kyoko Autinashi Nov 9 '93.
// use by angel for monk_guild

#include <mudlib.h>
#include "monk.h"    

inherit GUILD_OB;
inherit OBJECT;
mapping levels = ([]);

void create()
{
	guild_ob::create();
	seteuid( getuid() );
	set_class_name("monk");
#include <compress_obj.h>
	set_name("monk_book", "佛經");
	set_short("佛經");
	set_long( @LONG
這是一本泛黃的佛經。少林固然有號稱天下常勝不敗門派的美譽，也擁有笑傲武林的
武學經典，但是希望眾僧切勿以此為傲... 強中自有強中手，還是希望大家多多研習
佛經，早日超脫這個爭強奪勝的世界... 如果你想知道這本佛經的資料及使用，可用
\"help monk_book\" 指令。
LONG
	);

	set( "weight", 10 );
	set( "unit", "本" );
        
	set( "allow_material", ({ "cloth", "leather","wood","stone", }));
	set( "second_material", ({ "element", }));

	set( "extra_look", "$N隨身帶著一本破舊泛黃的佛經，上面用楷書寫著『少林』。\n");
}

void init()
{
	// Apply guild_ob checks
	guild_ob::init();

	add_action("help", "help");
	add_action("info", "info");
	add_action("do_comrades","monks");
	add_action("do_chat", "monk");
}

int do_comrades()
{
        object *usr, temp;
        int i, j;

        usr = filter_array( users(), "filter_monk", this_object() );
        usr = sort_array( usr, "sort_usrs", this_object() );
        if ( sizeof(usr) ) {
           i = sizeof(usr);
           write( 
             "目前共有 " + i + " 位少林武僧連線中:\n"
			 "==================================================\n");
           while(i--) {
                printf( "[ %2d ] %s (%s)\n", usr[i]->query_level(),
                  usr[i]->query("short"), capitalize(usr[i]->query("name")) );
           }
        } else 
           write("似乎沒有任何武僧在線上....。\n");
        return 1;
}

int sort_usrs( object u1, object u2 )
{
        return (int)levels[u1] - (int)levels[u2];
}

int filter_monk( object plr )
{        
        string name;
        if( (string)plr->query("class")=="monk" && visible(plr,this_player()) ) {
          levels[plr] = (int)plr->query_level();
          if( !levels[plr] || levels[plr] == 0 ) return 0;
          return 1;
        }
        return 0;
}

int do_chat(string arg)
{
        object *usr;
        int chinese_mode, i;
        chinese_mode = can_read_chinese();
        
        if( !arg ) return notify_fail(
          "你想對其它的少林武僧說什麼？\n");
        return guild_ob::guild_line(arg);
}

int info(string arg)
{
        
	switch(arg) {
		case "history":
		          cat( GUILD_DATA"c_monk_history" );
			break;
	    case "init":
	              cat( GUILD_DATA"c_monk_init" );
	        break;
	    case "skills":
	              cat( GUILD_DATA"c_monk_skills" );
	        break;
	    case "gonfu":
	            cat( GUILD_DATA"c_monk_gonfu" );
	        break;
	    case "commands":
	            cat( GUILD_DATA"c_monk_commands" );
	        break;
		case "topic":
		case "topics" :
		default : 
			cat( GUILD_DATA"c_topics");
			  break;
	}
	return 1;
}

int help( string arg )
{
    if( !arg || !id(arg) ) return 0;
	cat( GUILD_DATA"c_monkbook");
	return 1;
}
