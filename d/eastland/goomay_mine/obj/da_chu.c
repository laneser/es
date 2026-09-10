#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "quaff_potion", "drink" );
	add_action( "quaff_potion", "quaff" );
}

void create()
{
	set_name("da chu","陳年大麴");
	add("id" ,({"wine","chu"}) );
	set_short( "陳年大麴");
	set_long(@LONG
陳年大麴就是俗稱的：二鍋頭，因為要經過兩次發酵，擷取高粱的精華，酒精
濃度也特別高，在百分之六十以上，一般人是濃烈而難以入口的
LONG
);
   	set("unit","壺");
   	set("weight", 50);
   	set("value",({100, "silver"}) );
}

int quaff_potion(string arg)
{
	if( !arg || arg != "da chu" ) return 0;
	write( "你喝下一壺二鍋頭。感到全身開始發燙，但是有一種想吐的感覺。\n"
	       "你開始到處抓兔子！\n");
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"喝下一壺二鍋頭，然後"
		"開始在地上到處亂爬，不知道想做什麼？\n" , this_player()
	);
	remove();
	return 1;
}
