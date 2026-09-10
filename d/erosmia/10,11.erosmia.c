
#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short("On the Plain", "田野");
	set_long( @C_LONG_DESCRIPTION
你站在一望無際的田野上, 四周是美麗的小麥田。風吹過青翠的麥草,
揚起一陣陣綠色的波浪。北邊的遠方, 一座美麗的城鎮悠雅地斜倚於山丘
旁。正好面對著你南邊不遠處, 緩緩流過的大河。
C_LONG_DESCRIPTION
	);
	set_outside( "noden" );
	set( "exits", ([ 
		"north" : "/d/erosmia/ekravia/south_gate", 
		"east" : "/d/erosmia/11,11.erosmia", 
		"west"	:"/d/erosmia/9,11.erosmia",
		]) );
	set( "original", "d/erosmia/10,11" );
	set( "virtual_server", "/d/erosmia/virtual/erosmia_server" );
	set( "x_coordinate", 10 );
	set( "y_coordinate", 11 );
	reset();
}
