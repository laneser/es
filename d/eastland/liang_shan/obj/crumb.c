#include "../takeda.h"
inherit OBJECT;

void create()
{
     set_name("crumb","麵包屑");
     set_short("crumb","麵包屑");
     set_long(
      "一小塊吃剩的麵包屑，給人吃是絕對吃不飽的。\n"
      );
     set( "unit", "團");
     set("weight",5);
}
void init()
{
	add_action( "eat_food", "eat" );
}
int eat_food(string arg)
{
	if( !arg || arg != "crumb" ) return 0;
        write(
                "你把這一小團麵包屑吃下肚子，就好像在大海中丟入一顆石頭。\n" );
        tell_room( environment(this_player()),"你看到"+
                     this_player()->query("c_name")+"狼吞虎□地吃掉了一塊麵包屑，"
                "你的同情心油然而生...\n", this_player()
		);
           this_player()->receive_healing( 1+random(1) );
	remove();
	return 1;
}

