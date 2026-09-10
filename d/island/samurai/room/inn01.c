#include <mercury.h>

inherit ROOM;

void create()
{
	::create();
	set_short("千川樓前庭");
	set_long(@AAA
你來到千川樓的前庭，在道路的兩旁種植著一排排的灌木，還有一個接一
個排在一旁的精美雕像，而道路的左邊還有一個大噴泉，奇怪的是這個噴泉裡
居然都沒有長青苔，可見打掃人的勤勞．	
AAA
	);

	set_outside( "eastland" );
	set( "search_desc",([
	     "here":@AAA
你在這裡仔細搜索之後，發現這個噴泉(fountain)怪怪的！！　
AAA
]));
	set( "c_item_desc", ([ 
		"fountain" : @LONG_TEXT
這道噴泉你仔細觀察之後，發現在泉水噴出處似乎有一個暗色的
鐵板蓋板，你可以試著潛水(dive)下去看看．
LONG_TEXT
 ]) );
	set( "exits", ([ 
		"north" : MR"inn02", 
		"south" : MR"cac08" ]));
	set( "water_source",1 );
	reset();
}

void init()
{
	add_action( "do_dive", "dive" );
}

int do_dive(string arg)
{
	if( !arg || arg == "" || arg!="fountain" ){
		tell_object( this_player(), "你要潛去哪裡呀？\n" );
	        return 1;
	} 
        if( random( (int)this_player()->query_skill("swimming") ) < 5 ) {
		write( "你想潛入噴泉，卻被噴泉的水流給衝了回來\n" );
		return 1;
	}
	write( "你奮力潛向噴泉底部，果然不出所料，噴泉下還有一個通道\n"
		 );
	this_player()->move_player( MR"tube01", "SNEAK" );
        this_player()->set_explore("island#11");
	return 1;
}

