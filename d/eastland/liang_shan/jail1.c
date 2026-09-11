#include "takeda.h"

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
	set_short("監牢");
	set_long( @C_LONG_DESCRIPTION
你現在進入了一間漆黑的地牢，唯一你可發現的出口就是鎖起來的大鐵門
，除此之外都是光滑的巖壁，你想這可能是挖空山壁所成的地牢，四壁渾然天
成，全無接縫。牆上很突兀的長了一株植物(herb)，牆角放了張小石床，光是
看著就覺得好冷好冷，更別說是睡了。
C_LONG_DESCRIPTION
	);

	set( "c_item_desc", ([ 
		"herb" : @LONG_TEXT
你覺得奇怪，為何在這種地方還有植物生長呢? 在讚歎造物主之餘不免多看了
它幾眼，肥厚的葉片，墨綠色的斑紋，隱約散發出一股刺鼻的藥味。
LONG_TEXT
, 
		"bed" : @LONG_TEXT
這張小床是用石頭製成的，奇怪的是，它跟牆之間沒有任何接縫存在，大概也
是山壁直接雕成的，而且這張石床冰寒徹骨，你懷疑真有人能睡在上面。
LONG_TEXT
 ]) );
	set( "exits", ([ 
		"east" : TROOM"jail2" ]) );
	create_door( "east", "west", ([
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