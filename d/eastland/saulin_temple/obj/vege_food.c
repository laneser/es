#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
    set_name( "vegetarian meal", "素食大餐\" );
    add( "id", ({ "meal","vegetarian" }) );
    set_short( "素食大餐\" );
    set_long(@C_LONG
這是一份少林寺香積廚大廚師精心調配的素食大餐\，香噴噴的白
米飯加上香菇木耳，真是令人垂涎三尺，吃(eat) 了它以後想必
能提振一些精神吧!!
C_LONG
	);
   	set("unit", "份");
   	set("weight", 15);
   	set("value",({ 100, "silver"}) );
}

int eat_food(string arg)
{
	if( !id(arg) ) return 0;
	write( 
		"你狼吞虎□地吃掉了一份素食大餐\，拍拍肚皮打了一聲飽嗝...:)\n"
	);
	tell_room( environment(this_player()),
		this_player()->query("c__name")+"吃掉了一份素食大餐\，"
		"吃相簡直跟豬沒什麼分別...\n", this_player()
	);
	this_player()->receive_healing(20);
	remove();
	return 1;
}
