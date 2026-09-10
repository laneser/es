#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "drink_tea", "drink" );
}

void create()
{
	set_name("diet tea","減肥茶");
	add( "id" , ({ "tea" }) );
	set_short("diet tea" , "減肥茶");
	set_long(".." , 
		"這是一杯奇特的茶，碧綠的茶水發散出一陣陣濃郁的芬芳香氣，\n"
		"聞之使你精神大振。\n"
	);
   	set("unit","杯");
   	set("weight", 20);
   	set("value",({ 10000, "copper" }) );
}

int drink_tea(string arg)
{
	if( !arg || arg != "tea" ) return 0;
	else {write( "你慢慢的品嚐這杯減肥茶，忽然一陣奇怪的涼意從丹田開始，遊走全身...:)\n" 
		);
		tell_room( environment(this_player()), (
			this_player()->query("c_cap_name")+"喝下一杯減肥茶，然後露出奇怪的表情"
			"，你注意到他慢慢的瘦了下來\n" ), this_player()
		);
		this_player()->receive_healing( -15+random(5) );
	}
	remove();
	return 1;
}

