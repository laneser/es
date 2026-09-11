
#include "mercury.h"

inherit ROOM;

void create()
{
	::create();
	set_short("地下密室");
	set_long(@AAA
你來到一間地下密室，你開始確信這地下水道中一定有人居住，從
這房子的傢俱擺設來看，這個主人一定是個節儉的人，但你也感到奇怪
，為何這個人要躲到地下來住呢？在桌子旁有個奇怪的把手(lever) ．	
AAA
	);
        set("light",1);
	set( "c_item_desc", ([ 
		"lever" : @LONG_TEXT
這個把手你仔細觀察之後，發現好像可以拉拉看(pull)
LONG_TEXT
 ]) );
	set( "exits", ([
		"south" : MR"tube03" ]));
	reset();
}

void init()
{
	add_action( "do_pull", "pull" );
}

int do_pull(string arg)
{
	if( !arg || arg!="lever" )
		return notify_fail( "你要拉啥呀?\n" );
	write("你一拉把手，牆壁就裂開一個開口，你隨而進入牆壁裡面\n"
		 );
	this_player()->move_player( MR"tube05", "SNEAK" );
	return 1;
}

