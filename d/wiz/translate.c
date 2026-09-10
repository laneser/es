#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "中英文翻譯室" );
	set_long(
			"由於東方故事同時支援中文與英文兩種語言，所以在你的程式中必\n"
		"須同時提供兩種語言的訊息。若是你在翻譯或是加進你所不熟悉的語言\n"
		"訊息上有困難，可以在這裡留言請其它巫師幫忙。往西可以回到品質管\n"
		"制部。\n"
	);
	set( "light", 1 );
	set( "exits", ([
		"west"	:	"/d/wiz/qc-request"
	]) );

	// Cause the trans_board to load
	call_other( "/d/wiz/trans_board", "???" );
}
