#include <mudlib.h>
#include "wang.h"
inherit ROOM;

void create()
{
 	::create();
        set_short("書房");
	set_long(@C_LONG
這房間與其說是書房，不如說是起居室。房間的大部分被一張木床佔去了。
床頭有個小桌子，擺了文房四寶，墨都還沒乾。左邊的書架上放了一些關醫藥方
面的書。一邊的牆上掛了一幅畫。
C_LONG
);
	set("light", 1);
	set("exits",([
		"west" : WANG"room3",
	]));

	set("objects", ([
		"doctor" : WANG"mob/medic.c",
	]) );

	set("c_item_desc" , ([
		"painting" : "@@look_painting",
		"畫" : "@@look_painting",
	]));

        set("search_desc",([
        	"painting":"@@search_painting",
        	"畫" :"@@search_painting",
	]) );

	reset();
}
string look_painting()
{
	if ( (string) this_player()->query("class") == "healer" ) {
	return 
"這畫的邊緣有些磨損了, 好像有人常常拿起來觀賞。畫上有個古典美女, \n"
"看起來笑的很開心。你再仔細一看 咦, 長的跟刑大娘還蠻像的嘛。\n" ;
	} else {
	return 
"這畫的邊緣有些磨損了, 好像有人常常拿起來觀賞。畫上有個古典美女, \n"
"看起來笑的很開心。不知道這位美女是何方佳人。\n" ;
	}
}
string search_painting()
{
	write(
	"你發現這幅畫的後面果然有個通道, 於是你就走過去看看裡面有什麼東西。\n");	
	this_player()->move_player(WANG"room5","SNEAK",);
	return "";
}

