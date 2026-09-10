//#pragma save_binary

// File: /cmds/std/_secure.c
// by Kyoko, 06-06-1994

#include <mudlib.h>
#include <money.h>
#include <move.h>

inherit DAEMON;

int help();

int cmd_secure(string str)
{
	object player, *inv, ob;
	int chinese_mode, i;
	string type;
	
    player = this_player();
	chinese_mode = can_read_chinese();
	
	if(!str) return help();

	player->block_attack(2);

	if(str == "all") {
		inv = all_inventory(player);
		if( !pointerp(inv) || sizeof(inv) < 1 )
			return notify_fail("你身上沒有任何東西可標記。\n");
		for( i=0; i<sizeof(inv); i++) {
			if( !inv[i] || inv[i]->query("prevent_drop") ||
				inv[i]->query("secure") ) continue;
			tell_object( player,
				inv[i]->query("short")+"("+inv[i]->query("name")+
				")"+" --> 設定標記。\n" );
			inv[i]->set("secure", 1);
		}
		write( "Ok.\n" );
		return 1;
	}

	if(sscanf(str, "all %s", type) == 1) {
		inv = filter_array(all_inventory(player), "is_this_type",
			this_object(), type );
		if( !pointerp(inv) || sizeof(inv) < 1 )
			return notify_fail("你身上沒有這類東西可標記。\n");
		for( i=0; i<sizeof(inv); i++) {
			if( !inv[i] || inv[i]->query("prevent_drop") ||
				inv[i]->query("secure") ) continue;
			tell_object( player, 
				inv[i]->query("short")+"("+inv[i]->query("name")+
				")"+" --> 設定標記。\n" );
			inv[i]->set("secure", 1);
		}
		write( "Ok.\n" );
		return 1;
	}

	ob = present(str, player);
	if( !ob )
		return notify_fail("你身上沒有這樣東西。\n");
	if( ob->query("prevent_drop") )
		return notify_fail("你本來就無法丟掉這樣東西, 不必多此一舉了。\n");
	if( ob->query("secure") )
		return notify_fail("它已被設定標記了。\n");
	tell_object( player, 
		ob->query("short")+"("+ob->query("name")+
		")"+" --> 設定標記。\n" );
	ob->set("secure", 1);
	write( "Ok.\n" );
	return 1;
}

int is_this_type(object item, string type)
{
	if( !item->id(type) || item->query("prevent_drop") ) return 0;
	return 1;
}

int help()
{
	  write("使用格式: secure <item | all [type of items] | all>.\n\n"+
	     "藉由這個指令, 你可以將物品標記, 凡是被標記的物品將不會被移走。\n"+
	     "比如: give, drop, sell & toss 這些指令將會自動忽略所有被標記的\n"+
	     "物品。你可以用 unsecure 將標記移走。\n"+
	     "See also: unsecure。\n\n"
	  );
	return 1;
}
