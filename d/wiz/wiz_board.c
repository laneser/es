inherit "/std/board/bboard";
int query_max_msg() { return 50 ; }
int query_min_msg() { return 20 ; }
void create()
{
	bboard::create();
	set_attic_dir ("/d/wiz/data/attic");
	set_save_dir("/d/wiz/data");
	set_save_file("wiz_board");
	set_location("/d/wiz/wiz_office");
	set ("short.text", "巫師留言板");
	set ("long.text", "這是一個留言板，專供人留言紀事。詳細用法請參看 help board。\n"
						"這個留言板雖然是屬於巫師公會的，但任何人都歡迎在這裡留言。\n");
	replace_program("/std/board/bboard");
}
