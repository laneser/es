#include <hole.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "王宮入口" );
	set_long(@LONG
你現在的位置是蜥蜴人王宮的入口，不過怎麼看都不像是個達官
貴人的棲息場所，倒不如說是個洞穴更為恰當；或許這是因為蜥蜴人
天生就比較不講究居住環境所造成的。這兩個衛兵似乎正因為你的到
來而提高戒備。
LONG
	);
	set( "exits",([
			"up" : HOLE"hole34",
			"southeast" : HOLE"hole36",
			]) );
	set( "objects",([
			"lifeguard#1" : HMONSTER"life_guard",
			"lifeguard#2" : HMONSTER"life_guard"
			]) );
	reset();
#include <replace_room.h>
}
