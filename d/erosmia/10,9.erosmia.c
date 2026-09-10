
#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "平原" );
	set_long( @LONG_DESCRIPTION
你現在走在一片平地上，疏落的青草點綴著一些碎石，這裡開闊的視
野使你可以清楚地看到遠方的景物。
    南邊不遠處可以看到一座繁華的城鎮, 一道低矮的圍牆保護著它。從
這裡沒有路可以前往那城鎮。
LONG_DESCRIPTION
	);
	set_outside( "noden" );
	set( "exits", ([ 
		"north"	: "/d/erosmia/10,8.erosmia", 
		"east"	: "/d/erosmia/11,9.erosmia", 
		"west"	: "/d/erosmia/9,9.erosmia",
		]) );
	set( "original", "d/erosmia/10,9" );
	set( "virtual_server", "/d/erosmia/virtual/erosmia_server" );
	set( "x_coordinate", 10 );
	set( "y_coordinate", 9 );
	reset();
}
