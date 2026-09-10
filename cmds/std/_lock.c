//#pragma save_binary

//	File	:  /cmds/std/_lock.c
//	Creator	:  Mobydick@TMI (probably)
//	Rewrite	:  Watcher@TMI  (4/13/93)
//
//	This is the standard open command for doors. The object open
//	command is handled by the objects themselves.

#include <mudlib.h>

inherit DAEMON ;

int cmd_lock (string str)
{
	mapping doors;
	mixed *all_keys;
	object key, env;
	string *tmp, dir, key_name;
	int i;

	if( !str || str == "" )
		return notify_fail( "你要鎖上哪一個門？\n");

	env = environment(this_player());

	if(!env) return 0;
	dir = env->query_door(str);
	if( !dir ) return notify_fail("你要鎖上哪一個門？\n");

	//	Get the door mapping from the environment.
	doors = env->query("doors");

	if(!doors)
		return notify_fail("這裡沒有門可以鎖....\n");

	//	Check to see if we have the key.
	all_keys = filter_array(all_inventory(this_player()), "find_keys",
		this_object());

	if( !all_keys || sizeof(all_keys) < 1 )
		return notify_fail("你身上沒有任何鑰匙。\n");

	//	Get array of existing door directions.
	tmp = keys( doors );

	//  Check to see if the user can actually see.
	if(!this_player()->query("vision")) {
		write("你在黑暗中摸索找鑰匙孔....\n");
		dir = tmp[ random(sizeof(tmp)) ];
	}

	if(!doors[dir])
		return notify_fail("你要鎖上哪一個門？\n");

	//	Check to see if the door actually has a lock.
	if(!doors[dir]["lock"] || doors[dir]["lock"] == "none")
		return notify_fail(doors[dir]["c_name"] + "上沒有鑰匙孔。\n");

	//	Now check and see if the door is actually unlocked.
	if(doors[dir]["status"] == "locked")
		return notify_fail(doors[dir]["c_name"] + "已經鎖上了。\n");

	//	Hmmm...make sure the door is closed, too.

	if(doors[dir]["status"] == "open")
		return notify_fail("你必須先將" + doors[dir]["c_name"] + "關上。\n");

	//	See if the key fits.
	for( i=0; i<sizeof(all_keys); i++ )
		if( (string)all_keys[i]->query("to_lock") == doors[dir]["lock"] ) {
			key = all_keys[i];
			break;
		}

	if( !key )
		return notify_fail(
			"你試過身上所有的鑰匙，但是沒有一把能將" + doors[dir]["c_name"] + "鎖上。\n");

	//	Okay...lock the door, and update its linked mirror lock.

	env->set_status(dir, "locked");
	env->update_link(dir);

	write("你用" + key->query("short") + "把" + doors[dir]["c_name"] + "鎖上。\n");
	tell_room( env,
		(string)this_player()->query("c_name") + "把" + doors[dir]["name"] + "鎖上。\n",
		this_player() );

	return 1;
}

protected int find_keys(object obj) {  return (int)obj->id("key");  }

int help() {

	write( @C_HELP
Syntax: lock [object] with [optional desc] key

這個命令可以讓你用特定的鑰匙把門鎖上，當然，你必須先找到鑰匙。
C_HELP
);
return 1; }
