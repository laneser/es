inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir ("/d/adventurer/data/attic");
	set_save_dir("/d/adventurer/data");
	set_save_file("adventurer_board");
	set_location("/d/adventurer/hall/adv_guild");
	set ("short.text", "Adventurer's bulletin board");
	set ("c_short.text", "冒險者留言板");
	set ("c_long.text", "這是一個留言板，專供人留言紀事。詳細用法請參看 help board。\n"
						"由於冒險者公會是屬於大家的，因此任何人都歡迎在這裡留言。\n");
}
