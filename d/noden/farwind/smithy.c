//#pragma save_binary

#include "farwind.h"

inherit ROOM;

int box_moved;

void create()
{
	::create();
	set_short( "鐵匠鋪" );
	set_long(@C_LONG
這是遠風鎮上唯一的一家鐵匠鋪，老鐵匠平時最喜歡和年輕的冒險者談
論他年輕時的遊歷。但是最近為了對抗敵人的侵略，王宮來的使者訂了好幾
千套盔甲，他不得不加緊趕工。在鐵匠鋪的一個角落裡堆著一些箱子(boxes)
。
C_LONG
               	);
	set( "light", 1 );
	set( "exits", ([
		"west" : FARWIND"smain2"
	]) );

	set( "item_func", ([
		"boxes" : "exam_boxes"
	]) );
	box_moved = 0;

	set( "objects", ([
		"smith" : FARWIND"monster/smith"
	]) );
	reset();
}

void init()
{
	add_action( "do_move", "move" );
	add_action( "do_climb", "climb" );
}

void exam_boxes()
{
	object smith;

	if( !box_moved ) {
		write( 
			"這堆箱子零零散散地堆在一起，佔去了整個鐵匠鋪一半的面積。\n"
		);
		if( (smith= present("smith", this_object())) && smith->query("npc") )
			write( 
				"老鐵匠作個手勢，告訴你不要亂動(move)那些箱子。\n"
			);
	} else {
		write( 
			"這堆箱子中間被人搬開了一些，露出一到往下的梯子(ladder)。\n"
		);
		if( (smith= present("smith", this_object())) && smith->query("npc") )
			write( "老鐵匠告訴你: 地下室有不少老鼠，很兇喔。\n");
	}
}

int do_move(string arg)
{
	if( !arg || arg!= "boxes" ) return 0;
	if( box_moved ) {
		write( "你小心地把那些箱子搬回原位，遮住了那個向下的梯子。\n");
		box_moved = 0;
		delete( "item_desc/ladder" );
	} else {
		write("你小心地把那些箱子搬開，發現了一個向下的梯子(ladder)！\n"
		);
		box_moved = 1;
		add( "item_desc", ([ "ladder":
			"從這個梯子往下看一片漆黑，不知道爬(climb)下去會有什麼危險？\n"
		]) );
	}
	return 1;
}

int do_climb(string arg)
{
	if( !box_moved ) return 0;

	this_player()->move_player( FARWIND"cellar1", "SNEAK" );
	return 1;
}
