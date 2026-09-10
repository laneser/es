#include "farwind.h"
inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir ("/d/noden/data/attic") ;
	set_save_dir("/d/noden/data") ;
	set_save_file("bugs_board");
	set_location(FARWIND"square") ;
	set ("short.text", "ES bugs board");
	set ("c_short.text", "ES BUGS 留言板");
	set ("c_long.text", "這是一個留言板，專供人報告 BUGS 。詳細用法請參看 help board。\n"
		"由於 ES 是屬於大家的，因此希望任何人都在此報告所發現的 BUGS 。\n");
}
