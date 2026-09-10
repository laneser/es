#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "kick_rock", "kick" );
	add_action( "move_rock", "move" );
	add_action( "move_rock", "push" );
}

void create()
{
	seteuid(getuid());
	set_name("rock","大石頭");
	set_short("大石頭");
	set_long(
		"一顆非常大的石頭，看來相當的重。\n"
	);
   	set("unit","顆");
   	set("prevent_get",1);
   	set("weight", 10000);
}
int move_rock()
{
        write("這東西實在太重了，不管你怎麼努力都無法移動分毫\n");
        return 1;	
}

int kick_rock(string arg)
{
        object st1,st2,st3,st4,st5;
        if( !arg || arg != "rock" ) return 0;
        write("你非常不爽的用力踢這塊大石頭，沒想到竟然一腳把它踢碎了?\n");
        tell_room( environment(this_player()), 
	this_player()->query("c_name")+
         "非常不爽的用力踢那塊大石頭，沒想到竟然一腳把它踢碎了?\n"
			, this_player());
	st1 = new("/d/adventurer/natural_history/stone");
	st1->move(environment(this_object()));
	st2 = new("/d/adventurer/natural_history/stone");
	st2->move(environment(this_object()));
	st3 = new("/d/adventurer/natural_history/stone");
	st3->move(environment(this_object()));
	st4 = new("/d/adventurer/natural_history/stone");
	st4->move(environment(this_object()));
	st5 = new("/d/adventurer/natural_history/stone");
	st5->move(environment(this_object())); 
	                                       
	remove();
	return 1;
}

