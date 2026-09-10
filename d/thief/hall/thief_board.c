inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir ("/d/thief/data/attic");
	set_save_dir("/d/thief/data");
	set_save_file("thief_board");
	set_location("/d/thief/hall/thief_guild");
	set ("short.text", "Thief's bulletin board");
	set ("c_short.text", "小偷留言板");
	set ("c_long.text", 
		"這是一個留言板，專供人留言紀事。詳細用法請參看 help board。\n");
}
