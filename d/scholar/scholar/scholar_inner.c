#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
    set_short("Scholar Inner room", "墨竹軒");
	set_long( @LONG_DESCRIPTION
This is the inner hall of scholar's guild. .
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
你現在進入了書生公會內部的墨竹軒，這裡是書生們習武的地方，只有書生
公會的人才能進來，大廳中央有一本記載浩然正氣心法的書(book)。
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "book":@BOOK
書上以草書龍飛鳳舞地寫著[浩然正氣心法]，如果你要學習此心法必須是書生公
會的會員，如果你是的話只要下 study inner_force 你將會學到此內功心法。
BOOK
]));         
	set( "light", 1 );
	set( "exits", ([ 
	  "east"  : "/d/scholar/scholar/hall", ]) );
	reset();
}

void init()
{
	add_action("to_study","study");
}

int to_study(string arg)
{
	if( !arg || arg!="inner_force" ) return 0;
	if( (string)this_player()->query("class") !="scholar" )
		write("抱歉你不是本公會的人所以你不能學此心法\n");
	else if( (int)this_player()->query("force_effect") > 1 )
		write("你已經學過此心法不能再學\n");
	else {
		write("你經過一段長時間的的學習，終於領悟到浩然正氣功的內涵\n");
    	this_player()->set("force_effect", 2);
	}
	return 1;
}
