#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "研發部" );
	set_long(
			"這裡是東方故事的研發部，用來討論一些和 mudlib 介面，函數等\n"
		"技術性較高的研發項目。若是新增了什麼函數或定義了新的屬性也會在\n"
		"這裡發佈。往東走可以回到大巫師辦公室。\n"
	);
	set( "light", 1 );
	set( "exits", ([
		"east"	:	"/d/wiz/arch_office"
	]) );

	// Cause the RD_board to load
	call_other( "/d/wiz/RD_board", "???" );
}
