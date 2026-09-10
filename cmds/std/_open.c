//#pragma save_binary

// open.c
// Lets players open doors.
// Written by Mobydick@TMI-2, 1-8-93.
// Based on an earlier version by Rusty@TMI-2.
// Opening containers is handled by an add_action in the container, not by
// this command.
// Updated by Watcher@TMI-2 (03/28/93) to handle "open door".
// Watcher@TMI added vision checks (04/13/93).

#include <mudlib.h>

inherit DAEMON ;

int cmd_open (string str)
{
	string dir, *tmp;
	object env ;
	mapping doors ;

	if(!str || ( str!="door" && !(dir=environment(this_player())->query_door(str)) 
	&& sscanf(str,"%s door", dir) != 1))
		return notify_fail( 
			"你要打開甚麼東西？\n");

	env = environment(this_player());
	if (!env)
		return notify_fail( 
			"這裡甚麼也沒有，你要打開甚麼東西？\n");

	doors = env->query("doors") ;
 
	if (!doors)
		return notify_fail( 
			"這裡沒有門....。\n");
 
	tmp = keys( doors );
 
	if(str == "door") {
		if(sizeof(doors) > 1)
			return notify_fail( 
				"這裡的門不只一個，你要開哪一個？\n");

		dir = tmp[0];
	}
 
	//  If the user can't see ... then pick a random door. <grin>
	if(!this_player()->query("vision"))  {
		write( 
			"你在黑暗中摸索，找門....。\n");
		dir = tmp[ random(sizeof(tmp)) ];
	}
 
	if (!doors[dir])
		return notify_fail(
			"這個方向沒有門....。\n");

	if (doors[dir]["status"]=="open")
		return notify_fail( 
			"它已經被打開了。\n");

	if (doors[dir]["status"]=="locked")
		return notify_fail( 
			"咦....打不開，大概是鎖住了。\n");

	env->set_status(dir, "open");
	env->update_link(dir);
	printf( "你把%s打開。\n", doors[dir]["c_name"] );

	tell_room( env, 
		this_player()->query("c_name")+"打開了"+ doors[dir]["c_name"] + ".\n" ,
		this_player()
	);
	return 1 ;
}

int help() {
	write (@HELP
使用格式: open <方向> door  -or-  open <容器>

這個指令可以打開關閉的門或容器，但它必須是沒有鎖上的.

相關指令: get, put, close, lock, unlock.
HELP
	) ;
	return 1 ;
}
