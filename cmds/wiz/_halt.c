//#pragma save_binary
 
//	File	:  /cmds/xtra/_halt.c
//	Creator	:  Watcher@TMI  (04/04/93)
//
//	This command allows a wizard to halt the battle
//	of various object depending on input.

#include <mudlib.h>

inherit DAEMON ;
 
#define SYNTAX	"Syntax: halt [object | all]\n"
 
int cmd_halt(string str)
{
	mixed *attackers;
	object who, whoenv;
	int loop;

	if(!str || str == "" || str == "me")
		str = (string)this_player()->query("name");
 
	str = lower_case( str );
 
	// If a total end of battle is requested ... stop all battles
	// presently active within this room.
 
	if(str == "all" || str == "here" || str == "env") {

		//  Get all objects in the user's environment.
		attackers = all_inventory(environment(this_player()));

		//  Loop through and end all battles within the room.
		for(loop=0; loop<sizeof(attackers); loop++) 
		attackers[loop]->cease_all_attacks();

		write("Halt: 你制止了這場戰鬥。\n");
		tell_room(environment(this_player()), 
			(string)this_player()->query("c_name") + "用巫師的神力制止了這場戰鬥。\n",
			this_player());

	return 1; }
 
	// Find the requested object within the user's environment.

	whoenv = environment(this_player());
	if (!whoenv) {
		notify_fail("你認為在一片虛無中會有戰鬥嗎？\n");
		return 0;
	} 
	who = present(str, whoenv);
 
	if(str == (string)this_player()->query("name"))
		who = this_player();
 
	//		If the requested user isn't here ... tell em so.

	if(!who || !living(who)) {
	write("Halt: 這裡沒有叫這種名字的生物.\n");
	return 1; }
 
	//		Confirm the requested object is actually in a battle.
 
	if(!who->query_attacker()) {
		if(this_player() == who)
		write("Halt: 你現在不在戰鬥中.\n");
		else write("Halt: 這個東東目前沒有在作戰啊 !!\n");
	return 1; }
 
	//		Get a list of all the object's attackers.
 
	attackers = who->query_attackers();
 
	//		Loop through and remove the object's id from their attack array.
 
	for(loop=0; loop<sizeof(attackers); loop++)
		attackers[loop]->remove_attacker(this_player());
 
	//		And stop the specified object's attacks.
 
	who->cease_all_attacks();

	if(who == this_player())
			write("Halt: 你停止你的戰鬥.\n");
	else write("Halt: 你制止了"+who->query("c_name")+"的戰鬥.\n");
 
	tell_room(environment(this_player()),
		this_player()->query("c_name") + "用巫師的神力制止了"
		+( who == this_player() ? "他" : who->query("c_name") )
		+"的戰鬥。\n",
		this_player());
 
return 1; }
 
int help() {

	write( SYNTAX + "\n" +
	  "This command allows a wizard to end their own battle, or any present\n"+
	  "living object's battles by using the object's name as an argument.\n" +
	  "All battles can be ended within the room by using \"halt all\".\n");

return 1; }
 
