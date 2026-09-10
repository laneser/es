#include <mudlib.h>

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
   set_short("小巷");
	set_long( @LONG_DESCRIPTION
這條小巷向南北方向延伸，西邊的牆上似乎寫著什麼東西(writing)，在
你的南邊有一間小廟，東邊是一棟東方式的建築，雕樑畫棟，看起來好像是有
錢人的住所，你可以敲門(knock)看看主人是否願意讓你參觀一下。
LONG_DESCRIPTION
	);

	set_outside( "bluesand" );
	set( "item_desc", ([ 
		"writing" : "「徵臨時工，待優，請敲門三下。」\n\n" ]) );
    set( "exits", ([ 
		"north" : "/d/noden/bluesand/alley1.c", 
		"south" : "/d/noden/bluesand/temple.c", 
		"east" : "/d/healer/building/healer_guild" ]) );
	create_door( "east", "west", ([
		"keyword" : ({ "arch door", "door" }),
		"name" : "arch door",
		"c_name" : "拱門",
            "c_desc" : "一扇紅色的拱門，上面裝飾著許多銅環。\n",
		"status" : "closed"
	]) );
	reset();
}

void init()
{
   add_action( "do_knock", "knock" );
}

int do_knock(string arg)
{
   if( !arg || arg != "door" )
   return notify_fail( "你要敲啥?\n" );
   if( (string)this_object()->query("doors/east/status")=="open" )
   return notify_fail( "門是開著的, 直接走進去吧。\n" );
   write( "你用力地擂門三下。\n" );
   tell_room( this_object(),
        this_player()->query("c_name")+"用力地擂門三下。\n",
        this_player() );
   message( "tell_room",
        "西邊的門外傳來「咚..咚..咚..」的敲門聲。\n",
        "/d/healer/building/healer_guild", this_player() );
   return 1;
}
