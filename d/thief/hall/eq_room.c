#include <mudlib.h>
#include <move.h>
inherit ROOM;

void create()
{
	::create();
	set_short( "小偷公會秘密裝備室");
	set_long(	@C_LONG_DESCRIPTION
這裡是小偷公會的秘密儲藏室。幾年前一些有錢的小偷捐了些錢蓋了這座儲藏室,
給一些需要受訓的小偷把裝備留在這裡。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"east" : "/d/thief/hall/thief_shop" ]) );
	reset();
}
int clean_up() { return 0; }
void init()
{
	add_action("do_get","get");
}
int do_get(string arg)
{
	object *invs,ob;
	int i;
	
	if ( ! arg ) return 0;
	if ( arg == "all" ) {
		invs = all_inventory(this_object());
		for ( i = sizeof(invs)-1 ; i >=0 ; i -- ) {
		if ( (string)invs[i]->query("owner") != (string)this_player()->query("name") )
//			&& !wizardp(this_player()) )
			continue ;
		if ( invs[i]->move(this_player()) != MOVE_OK )
			continue ;
		invs[i]->delete("owner");			
		}
		tell_object(this_player(),"你把你的東西全部揀了起來。\n");
		return 1;
	}
	if ( !ob = present(arg,this_object()) )
		return 0;
	if ( (string)ob->query("owner") != (string)this_player()->query("name") ) {
//		&& !wizardp(this_player()) )
		tell_object(this_player(),"這件東西你不能拿走。\n");
//		return notify_fail("這件東西你不能拿走。\n");
		return 1;
	}
	call_other("/cmds/std/_get","cmd_get",arg);
	ob->delete("owner");
	return 1;
}
