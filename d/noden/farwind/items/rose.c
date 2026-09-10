#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "quaff_potion", "drink" );
	add_action( "quaff_potion", "quaff" );
}

void create(){

	set_name("Rose wine","玫瑰紅酒");
	add( "id" , ({ "rose","wine" }) );
	set_short( "玫瑰紅酒" );
	set_long( "這是從藍沙港商人處買來的玫瑰紅酒\n" );
   	set("unit","杯");
   	set("weight", 10);
   	set("value",({20, "silver"}) );
}

int quaff_potion(string arg)
{

	if( arg != "rose" ) return 0;
	write( can_read_chinese()?
		"你喝下一杯玫瑰紅酒，感到十分的舒服。\n":
		"You drink a cup of Rose Red wine....\n"
	);
	tell_room( environment(this_player()), ({
		this_player()->query("cap_name")+" drink an nice chinese wine....\n",
		this_player()->query("c_cap_name")+"喝下一杯玫瑰紅酒，輕輕地閉上眼睛，好像很舒服的樣子。。\n"}),
		this_player() );

	remove();
	return 1;

}
	
