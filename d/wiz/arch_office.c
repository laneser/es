#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "大巫師辦公室" );
	set_long(
			"這裡是大巫師們辦公的地方，八張嶄新桃木桌整齊地排列在房間，看\n"
		"起來 ... 似乎情況和巫師辦公室差不多。東邊是人事室 ，西邊是研發部\n"
		"，南邊有一道看起來很不起眼的木門，上面掛著一個牌子(sign)。\n"
	);
	set( "item_desc", ([
		"sign" : "The sign reads: \"God Office\".\n"
	]) );

	set( "c_item_desc", ([
		"sign" : "牌子上寫著: 神的辦公室，非請莫入。\n"
	]) );

	set( "light", 1 );

	set( "exits", ([
		"north"	:	"/d/wiz/wiz_office",
		"west"	:	"/d/wiz/RandD"
	]) );

	// Cause the arch_board to load
	call_other( "/d/wiz/arch_board", "???" );
}
