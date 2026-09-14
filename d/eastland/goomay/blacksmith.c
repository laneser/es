#include "goomay.h"

inherit ROOM;

int furnace_moved;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "劍廬" );
        set_long(
@LONG
你走進一家打鐵鋪子，此起彼落的打鐵聲響成一片，黝黑的地面上鋪滿
了一層細鐵屑，那些都是打鐵時濺落的火花。鋪內擺了許多火爐和鐵砧，有
幾名鐵匠正在工作。店堂上懸著一方巨大的黑匾，上面提著「劍廬」兩個大
大的金字，你仔細一看題款，哇 !! 原來是今上御筆，原來這裡就是名聞天
下的鑄劍師－段鐵的家。
LONG
        );

        set( "exits", ([
                "south" : Goomay"row22", ]));

	set( "item_func", ([
		"furnace" : "exam_furnace"
	]) );
	furnace_moved = 0;

        set( "objects", ([
                "smith1" : Mob"smith",
                "smith2" : Mob"smith",
                "master" : Mob"master_smith",
				"guest"  : Mob"traveller",
        ]) );

	reset();
}

void init()
{
	add_action( "do_move", "move" );
	add_action( "do_climb", "climb" );
}

void exam_furnace()
{
	object smith;

	if( !furnace_moved ) {
		write("這些爐子整齊地排著。\n");
		if( (smith= present("smith", this_object())) && smith->query("npc") )
			write("鐵匠作個手勢，告訴你不要亂動他的爐子。\n");
	} else {
		write("這個爐子被人移開了一些，露出一個黑黝黝的地洞。\n");
		if( (smith=present("smith", this_object())) && smith->query("npc") )
			write("鐵匠告訴你: 這陣子洞裡常常傳出一些怪聲，你可要自己小心。\n");
	}
}

int do_move(string arg)
{
	if( !arg || arg!= "furnace" ) return 0;
	if( furnace_moved ) {
		write("你把那個爐子搬回原位，遮住了那個地洞。\n");
		furnace_moved = 0;
		delete( "c_item_desc/hole" );
	} else {
		write("你小心地把那個爐子搬開，發現了一個黑黝黝的地洞 !\n");
		furnace_moved = 1;
		add( "c_item_desc", ([ "hole":
			"從這個地洞往下看一片漆黑，不知道爬下去會有什麼危險？\n"
		]) );
	}
	return 1;
}

int do_climb(string arg)
{
        if( !furnace_moved )
        return notify_fail("你在地上到處亂爬。\n");
        tell_room( this_object(), 
        this_player()->query("c_name") + "試著爬入地洞...哎呀 ! 他頭下腳上的栽進去了，技術實在是 ...\n",
                this_player() );

	this_player()->move_player( Goomay"cellar1", "SNEAK" );
        tell_room( Goomay"cellar1", 
                this_player()->query("c_name") + "從洞口直直的栽了下來。\n"
                ,this_player() );

	return 1;
}
