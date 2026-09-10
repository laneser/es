#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "quaff_potion", "drink" );
	add_action( "quaff_potion", "quaff" );
}

void create(){

	set_name("xo","ＸＯ");
	add( "id" , ({ "wine","xo" }) );
	set_short( "ＸＯ" );
	set_long( "ＸＯ，還要解釋嗎？喝下就是了。\n" );
   	set("unit","杯");
   	set("weight", 10);
   	set("value",({30, "silver"}) );
}

int quaff_potion(string arg)
{

	if( ! id(arg) ) return 0;
	write (
		"你喝下一杯ＸＯ。感到頭有點暈暈的，但是有一種興奮的感覺。\n你高興得唱起歌來...\n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"喝下一杯ＸＯ，然後醉薰薰的唱起歌來.....還真難聽!!\n",
		this_player() );

	remove();
	return 1;

}
	
