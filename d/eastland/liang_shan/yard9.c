#include "takeda.h"

inherit ROOM;

void create()
{
	object dong;
	::create();
	set_short( "庭院月門" );
	set_long(
	"這是一個圓型的小門，在東方大陸，這種門通常是庭院的出入口，在門的\n"
	"另一邊你看到一座小小的庭院(yard)，裡面花木扶疏，但因距離太遠，看不清\n"
	"楚種的是什麼。\n"
	);
        set( "c_item_desc", (["yard":
        "當你注視著這座庭院，有股說不出的詭異感覺在心中擴散，你的第六感阻\n"
        "止了你進入的念頭。\n"
        ]));
        set_outside("eastland");
        set( "exits", ([
                "east" : TROOM"yard8",
                "south" : TROOM"hall"
        ]) );
        dong = new(TMONSTER"dong");
        dong->move(this_object());
        set( "pre_exit_func",([
               "east" : "check_leave"
        ]));
        reset();
}
int check_leave()
{
write( 
"走過這道大門，你的心情不由自主的緊張起來，就像走入了一片原始森林，自己\n"
"忽然沒來由的覺得自己十分渺小，四面八方都像是充滿了不可測的危險。\n\n");
return 0;
}
int clean_up() { return 0; }
