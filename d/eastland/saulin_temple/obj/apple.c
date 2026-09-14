#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
        set_name( "apple", "蘋果" );
        add( "id", ({ "apple" }) );
        set_short( "蘋果" );
        set_long(@C_LONG
這是一個紅蘋果，看起來十分新鮮美味，吃(eat)了它以後想必
能提振一些精神吧 !!
C_LONG
		);
   		set("unit","顆");
   		set("weight", 10);
   		set("value",({40, "silver"}) );
}

int eat_food(string arg)
{
	if( !arg || arg != "apple") return 0;
	write( "你狼吞虎嚥地啃掉了一顆蘋果，覺得齒頰留香...:)\n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"三兩下就啃掉了一顆蘋果，你都看呆了...\n"
		, this_player()
	);
	this_player()->receive_healing(5);
	remove();
	return 1;
}
