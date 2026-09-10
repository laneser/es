//#pragma save_binary
#include <mudlib.h>
#include "/d/thief/thief.h"

inherit GUILD_OB;

inherit WEAPON;

void create()
{
	guild_ob::create();
	seteuid(getuid());
	set_class_name("thief");
	if (clonep(this_object())) {
		set_default_ob(__FILE__);
		return ;
	}
	set_name("universal dagger", "萬用小刀");
	add("id",({ "dagger" }) );
	set_short("萬用小刀");
	set_long(@LONG
這是一把小偷專用的多用途摺疊小刀，可以用來開鎖、挖牆縫、割錢包等等
，雖然看起來不怎麼起眼，但是在一個有經驗的小偷手中，卻可以成為救命
謀生的工具。你可以試試 help dagger 以獲得進一步的說明。
LONG
	);

	set( "unit", "把" );
    	set( "weapon_class", 9 );
    	set("type","dagger");
    	set( "min_damage", 4 );
    	set( "max_damage", 8 );
	set( "weight", 5 );
	set( "extra_look", "$N帶著小偷專用的萬用小刀。\n");
}

void init()
{
	// Apply guild_ob checks
	guild_ob::init();

	add_action("help", "help");
	add_action("info", "info");
	add_action("do_fellows", "thieves");
	add_action("do_chat", "whisper");
}

int do_fellows()
{
//	return guild_ob::list_guild_members();
        object *usr;
        int i,guild_lv;

        usr = filter_array( users(), "filter_members", this_object() );
        usr = sort_array( usr, "sort_members", this_object() );
        if( sizeof(usr) ) {
                owner->quick_message(
          "目前共有 " + sizeof(usr) + " 位"+to_chinese(class_name)+"連線中:\n"
                        + "==================================\n");
             for( i=0; i<sizeof(usr); i++ ) {
		
		guild_lv = ( (int)usr[i]->query("thief_level/backstab") +
			     (int)usr[i]->query("thief_level/throw-dagger") ) /2;
		if ( wizardp(owner) && (int)usr[i]->query("make-up") == 1 )
                    owner->quick_message(
			sprintf( "[ %2d | %2d ] %s (%s) [由 %s 裝扮] \n",
			usr[i]->query_level(),guild_lv,
			usr[i]->query("short"),
			capitalize(usr[i]->query("name")) ,
			capitalize(usr[i]->query("org_name")) 
		    ));
		else 
                    owner->quick_message(sprintf( "[ %2d | %2d ] %s (%s) \n",
                        usr[i]->query_level(),guild_lv,
                        usr[i]->query("short"), 
			capitalize(usr[i]->query("name")) 
		    ));
	    }
        } else
                owner->quick_message(
                        "似乎沒有任何"+to_chinese(class_name)+"公會的成員在線上.
...。\n");
        return 1;
}

// The guild channel
int do_chat(string arg)
{
	if( !arg )
		return notify_fail("你想對其它小偷同業說什麼？\n");
	return guild_ob::guild_line(arg);
}

int info(string arg)
{
	switch(arg) {
		case "history": cat( GUILD_DATA+"c_thief_history" );
			break;
	    case "commands": cat( GUILD_DATA+"c_thief_commands" );
			break;
		case "topics":
		default: 
write( @C_TOPICS
小偷公會是一個隱秘性很高的公會，你可以用 info 指令取得有關以下主題的
公會資訊:
    history    - 有關小偷公會的歷史。
    commands   - 有關小偷能使用的特殊指令。
    
C_TOPICS
			);
			break;
	}
	return 1;
}

int help(string arg)
{
	if( !arg || arg!="dagger" ) return 0;
	cat(GUILD_DATA+"c_uni_dagger");
	return 1;
}
