#include <mudlib.h>
#include "wang.h"

inherit ROOM;

void create()
{
	::create();
    	set_short("密室");
	set_long( 
		 @C_LONG_DESCRIPTION
這裡是王藥師的密室，看起來還蠻乾淨的，好像常常有人出入。不過這裡的
東西實在少的可憐，只有左手邊有一張桌子，桌上放著一本有點舊的書。
C_LONG_DESCRIPTION
	);

	set( "c_item_desc", ([ 
		"book" : @LONG_TEXT
這本書應該是王藥師的筆記吧，藏個這麼秘密。你可以查看(read)這本書的
藥方表(list)。
LONG_TEXT
 ]) );
    	set( "exits", ([ 
		"west" : WANG"room4" ]) );
	reset();
}

void init()
{
	add_action( "do_read", "read" );
}

int do_read( string str )
{
	int page;

	if( !str || str=="" ) return notify_fail( "閱讀什麼？\n" );
	if( str=="list" ) {
		cat(POISON_INFO"c_list"); 
		return 1;
	} else if( sscanf(str, "page %d", page)==1 ) {
		if ( file_exists(POISON_INFO"c_page" + page) )
			cat( POISON_INFO"c_page" + page );
		else
			write("這頁字跡模糊，你怎樣用力也看不清楚\n");
		return 1;
	}
}
