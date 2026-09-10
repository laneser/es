#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "品質管制部" );
	set_long(
			"這裡是巫師創作的品質管制部，所有要開放讓玩家接觸得到的區\n"
		"域，物品都必須經過品質管制部的審核。將你要申請品質檢驗的內容\n"
		"( 格式請參照 \"help policy\" )寫在這裡的留言板上，大巫師們會\n"
		"儘快加以審核並將結果放在這裡。在你東邊的是中英文翻譯室。\n"
	);
	set( "light", 1 );
	set( "exits", ([
		"west"	:	"/d/wiz/wiz_office",
		"east"	:	"/d/wiz/translate"
	]) );

	// Cause the QC-request board to load
	call_other( "/d/wiz/qc_board", "???" );
}
