// chainmail.c
// A standard piece of armor, heavily commented to explain what all the
// properties are.
// Created by Mobydick@TMI-2, 9-30-92

#include <mudlib.h>

inherit ARMOR ;

void create()
{
	set_name( "wedding suit", "新娘禮服");
	add( "id", ({ "suit", "wedding suit" }) );
	set_short( "a white wedding suit", "白色新娘禮服");
	set_long(
		"This is a white, beautiful wedding suit.\n",
		"這是一件純白色的結婚禮服, 在婚禮時新娘穿上它接受大家的祝福。\n" +
		"它美麗的樣式與其所代表的意義不知令多少少女嚮往不已。\n"
	);
	set( "type", "body" );
	set( "armor_class", 20 );
	set( "defense_bonus", 15 );
	set( "weight", 10 );
	set( "value", ({ 100, "gold" }) );
	set( "unit", "件" );
}

void init()
{
	add_action("do_wear", "wear");
}

int do_wear(string str)
{
	if ( (string)this_player()->query("gender") != "female") {
	printf( can_read_chinese() ? 
				"別開玩笑了, 你想當人妖嗎?\n" :
				"You are sure kidding!\n");
	return 1;
	}
}
		
