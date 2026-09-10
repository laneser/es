//#pragma save_binary
// _say.c
// The ghost's say command. It won't actually give his message, but it will
// at least indicate to live players that he's around and unhappy. Clever
// ghosts will manage to communicate using this. ("One gust for yes, two
// gusts for no. Is your corpse north of here?")
// Written by Mobydick, 11-14-92. Loosely based on the existing player _say
// command.

#include <mudlib.h>

inherit DAEMON ;

int cmd_say (string str)
{
	write( 
		"你縱然有千言萬語想說，但是對其他陽世間的人而言只是一陣陰風慘慘而已。\n",
	);
	tell_room( environment(this_player()), 
		"你感到一陣陰森的涼意，似乎聽到什麼聲音。\n",
		this_player() );
	return 1;
}
