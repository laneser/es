
#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "山丘小徑" );
	set_long( @LONG_DESCRIPTION
你走在低矮的山丘上, 周圍是美麗的草原與花朵。東方的山腳下可以
望見一個美麗的城鎮。從那邊, 一條小徑蜿蜒而來, 橫過你的面前, 連往
西邊的山中。
LONG_DESCRIPTION
	);
	set_outside( "noden" );
	set( "exits", ([ 
		"north"	: "/d/erosmia/9,9.erosmia", 
		"east"	: "/d/erosmia/ekravia/west_gate", 
//		"west"	: "/d/erosmia/8,10.erosmia",
		"south"	: "/d/erosmia/9,11.erosmia",
		]) );
	set( "original", "d/erosmia/9,10" );
	set( "virtual_server", "/d/erosmia/virtual/erosmia_server" );
	set( "x_coordinate", 9 );
	set( "y_coordinate", 10 );
	reset();
}
