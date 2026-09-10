//#pragma save_binary

// translation done. 2-21-94  -Elon

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short("遠風鎮西門");
	set_long( @C_LONG_DESCRIPTION
這裡是遠風鎮西邊的大門，路旁有一棵大樹(tree)，北邊是一間白色
的屋子(house)，往南是一條小路通往河邊，西邊出了大門是一座橋，你
聽到橋下除了潺潺的流水聲外，好像還有一些鵝叫聲。
C_LONG_DESCRIPTION
	);

	set_outside( "farwind" );
	set( "light", 1 );
	set( "exits", ([
		"west" : "/d/noden/farwind/bridge",
		"south" : "/d/noden/farwind/path1",
		"east" : "/d/noden/farwind/wbazz"
	]) );
	set( "item_desc", ([
		"tree" :
			"一棵又粗又大的榕樹，長在路旁，也許你可以爬(climb)上去瞧瞧？\n",
		"house" :
			"一間看起來相當講究的屋子，雖然外觀有些破舊，但是屋主似乎很小\n"
			"心地保養這棟房子，屋子的門沒有關，你可以進去(enter)瞧瞧。\n",
    ]) );
    set( "objects", ([
		"wild dog" : "/d/noden/farwind/monster/dog"
	]) );
	reset();
}

void init()
{
	add_action( "climb_tree", "climb" );
	add_action( "enter_house", "enter" );
}

int climb_tree( string arg )
{
	if( !arg || arg!="tree" )
		return notify_fail( "爬什麼？\n" );
        if( random( 15 ) >=this_player()->query_skill("climbing") )
		return notify_fail( "你企圖爬上榕樹，但是一不小心掉了下來。\n");
	this_player()->move_player( "/d/noden/farwind/tree1", "SNEAK" );
	tell_room( this_object(), 
		this_player()->query("c_name") + "爬到樹上。\n",
		this_player() );
	return 1;
}

int enter_house( string arg )
{
	if( !arg || arg!= "house" )
		return notify_fail( "進入哪裡？\n" );
	this_player()->move_player( "/d/noden/farwind/healer", "SNEAK" );
	return 1;
}
