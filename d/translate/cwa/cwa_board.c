#include <mudlib.h> 
inherit "/std/board/bboard";

void create()
{
	::create();
	set_attic_dir ("/u/s/supertramp/cwa") ;
	set_save_dir("/u/s/supertramp/cwa") ;
	set_save_file("cwa_board");
	set_location("/u/s/supertramp/cwa/cwa_club") ;
	set ("short.text", "CWA's bulletin board");
	set ("c_short.text", "色狼協會留言板");
	set ("c_long.text", "這是一個留言板，專供色狼們留言紀事。詳細用法請參看 help board。\n"
        );
}
