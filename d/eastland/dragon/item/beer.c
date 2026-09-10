// This is a standard healing potion. 
// Created by Annihilator@Eastern.Stories 11-22-93
#include <mudlib.h>

inherit OBJECT;

void create()
{
        seteuid(getuid());
        set_name( "chinese beer", "陳年女兒紅" );
        add( "id",({ "beer" }) );
        set_short( "陳年女兒紅" );
        set_long(
            "這是由一個古老的國家所傳下的名酒。\n"
        );
        set("layuter_beer",1);
        set( "unit", "瓶");
        set( "weight", 10 );
        set( "value", ({ 20, "gold" }) );
}


void init()
{
	add_action( "drink_beer", "drink" );
}

int drink_beer(string arg)
{
	int kar, heal;
	string unit;

	if( !arg || (arg!="beer") ) return 0;
	if( environment() != this_player() )
		return notify_fail("你身上沒有這樣東西。\n");
	write("你喝下一喝下一瓶陳年女兒紅。\n");
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"喝下一瓶陳年女兒紅。\n",
		this_player() );
	heal = 20;
	this_player()->receive_healing( heal );
	remove();
	return 1;
}
