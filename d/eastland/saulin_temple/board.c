#include <mudlib.h>  
#include "saulin_temple.h"
inherit "/std/board/bboard";

void create()
{
	bboard::create();
	set_attic_dir ("/d/eastland/data/attic");
	set_save_dir(/d/eastland/data);
	set_save_file("board");
        set_location(SAULIN"monk_guild");
	set ("short.text", "openion board");
	set ("c_short.text", "少林公會留言板");
	set ("c_long.text", 
@DESC
這是一個留言板，供人報告 BUGS 、提供點子，詳細用法請參看 help board。
由於少林寺及其公會是新區域，希望大家多多發言，讓我們做得更好 !!
DESC
);
}
