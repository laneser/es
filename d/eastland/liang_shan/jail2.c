#include <takeda.h>

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
	set_short("洞穴");
	set_long( @C_LONG_DESCRIPTION
這裡是一個天然形成的巖洞，西邊有一扇厚實的大鐵門，從門縫中傳來一
陣陣的寒氣，砭人肌膚，據說裡面是個地牢，真不知道那些犯人是怎麼熬下去
的，牆邊有一張小桌子，一個漢子正坐在桌邊喝酒驅寒。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"west" : TROOM"jail1",
	        "southwest" : TROOM"down_hall"
	        ]));
	set( "objects", ([
	        "han" : TMONSTER"han" 
	        ]));
	create_door( "west", "east", ([
	        "keyword" : ({"door", "iron door"}),
		"name" : "iron door",
		"c_name" : "鐵門",
		"desc" : "A strudy iron door",
		"c_desc" : "一扇厚實的大鐵門",
		"status" : "locked",
		"lock" : "LiangShankey-1"
	]) );
	reset();
}
int clean_up() { return 0; }