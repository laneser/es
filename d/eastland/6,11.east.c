
#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short("山丘");
	set_long( @LONG_DESCRIPTION
    你正走在一由一些低矮山丘組成的丘陵地上，這裡的地勢起伏
並不很大，青鬱的短草覆蓋著舉目所及的山丘，幾株大樹散佈在山
坡上，樹間錯落著幾塊巨巖(rocks)。
LONG_DESCRIPTION
	);

	set_outside( "eastland" );
       set("c_item_desc",(["rocks":@C_LONG
    這些巨巖不知道擺在這裡幾百年了，巖上佈滿了青苔，你想走上前
去仔細打量它們，卻發現近近的路怎麼走也走不到，走了半天，突然被
草叢裡的某見東西絆了一交，原來是根粗繩(rope)，不知道誰把它釘在
草叢裡。
C_LONG
			,"rope" : @ROPE
    你仔細看看這段繩索，發現它還不太舊，被人用木釘彎彎曲曲的釘
在地上，不知道有什麼用意，你想循著(follow)它去看看嗎？
ROPE
]));

	set( "exits", ([ 
		"north" : "d/eastland/6,10.east", 
		"east" : "d/eastland/7,11.east" ]) );
	set( "original", "d/eastland/6,11" );
	set( "virtual_server", "/d/eastland/virtual/east_server" );
	set( "x_coordinate", 6 );
	set( "y_coordinate", 11 );
	reset();
}

void init()
{
	add_action("do_trace","follow");
}

int do_trace(string arg)
{
        if( !arg || arg!="rope" ) 
		return notify_fail("追蹤什麼？\n");

        write("你順著繩索彎彎曲曲的前進，突然，腳下一個踩空....\n");
        this_player()->set_explore("eastland#0");
        tell_room( this_object(), 
		  this_player()->query("c_cap_name") + "彎彎曲曲的走來走去，你聽到一聲大叫，然後人就不見了....\n",
                this_player() );
        this_player()->move_player( "/d/eastland/tomb/maze1", "SNEAK" );
        tell_room( "/d/eastland/tomb/maze1", 
                this_player()->query("c_cap_name") + "從上面的洞口掉了下來。\n",
                this_player() );
        return 1;
}
