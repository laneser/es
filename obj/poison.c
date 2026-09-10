#include <mudlib.h>
#include <conditions.h>

inherit OBJECT;

void create()
{
	set_name( "poison pouch", "毒藥包" );
	add( "id", ({ "pouch", "poison" }) );
	set_short( "毒藥包" );
	set_long(
		"這是一包毒藥粉，如果你要使用這包毒藥，用 poison <某人>。\n" );
	set( "weight", 20 );
	set( "value", ({ 300, "silver" }) );
}

void init()
{
	add_action( "do_poison", "poison" );
}

int do_poison(string arg)
{
	object dest;

	if( !arg || arg=="" || !(dest = present(arg, environment(this_player()))) )
		return notify_fail("你要用毒藥害誰？\n");
	if( !living(dest) ) return notify_fail("做這種事情一點意義也沒有....。\n");
	if ( userp(dest) && (int)dest->query_level()< 5 )
		return notify_fail("你不能陷害低等級玩家。\n");
	call_other( CONDITION_PREFIX"simple_poison", "apply_effect", dest, 10, 20 );
	write(sprintf("你把毒藥粉灑在%s身上！\n",dest->query("short")));
	tell_object( dest, 
		    sprintf("%s把一包毒藥粉灑在你身上！\n",this_player()->query("c_name")));
	tell_room( environment(this_player()), 
		  sprintf("%s把一包毒藥粉灑在%s身上！\n",
			  this_player()->query("c_name"),
			  dest->query("short")),
		({ this_player(), dest }) );
	if( dest!=this_player() ) {
		dest->kill_ob(this_player());
		this_player()->kill_ob(dest);
	}
	remove();
	return 1;
}
