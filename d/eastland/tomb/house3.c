#include <almuhara.h>
 
inherit ROOM;
 
void create()
{
	::create();
	set_short("臥室");
	set_long( 
@C_LONG_DESCRIPTION
你走進了一間不大的臥室，和外面比較之下，這兒顯的相當樸素。除了普通的傢俱外，
就數一個箱子最奇特。箱子成八卦形狀，上面有著四個小凹槽，左右兩旁各有一龍形的把手
，不知道是用來放什麼東西的。你環顧四周，卻找不到什麼有趣的東西了。
C_LONG_DESCRIPTION
	);
 
	set( "exits", ([ 
		"north" : TOMB"/house2",  ]) );
	set( "objects", ([
		"wife" : MOB"/wife" ]) );
        set("c_item_desc",(["box":@C_LONG
這個箱子看來奇怪，但是你實在研究不出它是幹啥用的......也許你該問問主人。
C_LONG
      ]));
	reset();	
#include <replace_room.h>
}
 
