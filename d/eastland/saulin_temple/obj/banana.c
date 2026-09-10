#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create(){

        set_name( "banana", "香蕉" );
        add( "id", ({ "banana" }) );
        set_short( "香蕉" );
        set_long(@C_LONG
這是一條香蕉，看起來十分新鮮美味，吃(eat)了它以後想必
能提振一些精神吧 !!
C_LONG
		);
   		set("unit","條");
   		set("weight", 5);
   		set("value",({40, "silver"}) );
}

int eat_food(string arg)
{
	if( !arg || arg != "banana") return 0;
	write( 
		"你狼吞虎□地吃掉一條香蕉，覺得齒頰留香...:)\n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"三兩下就吃掉一條香蕉，你都看呆了...\n"
		, this_player()
	);
	this_player()->receive_healing(5);
	remove();
	return 1;
}
