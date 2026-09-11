#include "hole.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "地下王宮" );
	set_long(@LONG
你現在所站的的位置是蜥蜴人王宮的第二層，不過怎麼看都不像
是個達官貴人的棲息場所，倒不如說是個洞穴更為恰當；或許這是因
為蜥蜴人天生就比較不講究居住環境所造成的。
LONG
	);
	set( "exits",([
			"south" : HOLE"hole40",
			"north" : HOLE"hole44",
			"west" : HOLE"hole41",
			"east" : HOLE"hole43",
			]) );
	reset();
#include <replace_room.h>
}
