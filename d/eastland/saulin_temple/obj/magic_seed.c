#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "Relic of Damo", "達摩舍利子" );
	add( "id", ({ "relic" }) );
	set_short( "達摩舍利子" );
	set_long(@C_LONG
這雖然只是顆小小的舍利子，但上面寶光流動，顯得十分不平凡，據說
它可以抵禦三昧真火。要使用舍利子，用 throw <someone>。
C_LONG
	        );
	set( "unit", "顆" );
	set( "weight", 5 );
	set( "value", ({ 100, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
	add_action( "do_throw", "throw" );
}

int do_throw(string arg)
{
	object obj;

	if( !arg )
		return notify_fail("要用舍利子丟誰？\n");
	if( !( obj = present(arg, environment(this_player())) ) )
		return notify_fail( "這裡沒這個人。\n");
	if( undefinedp(obj->query("zapped")) ) {
		write( 
			"你拿出舍利子丟向"+obj->query("c_short")+"，不過對方似乎不受影響。\n"
		);
		tell_room( environment(this_player()), 
			this_player()->query("c_name")+
			"拿出一顆小小的東西丟向"+obj->query("c_short")+"。\n"
			, this_player()
		);
	} else {
		write( 
			"你拿出舍利子丟向"+obj->query("c_short")+".... \n" 
		);
		tell_room( environment(this_player()), 
			 this_player()->query("c_name")+
			"拿出一顆舍利子丟向"+obj->query("c_short")+"。\n"
			, this_player()
		);
		write( "你的舍利子直直的向"+obj->query("c_short")+"的面門打去。\n");
		obj->zapped();
		remove();
	}
	return 1;
}
