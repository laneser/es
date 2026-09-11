#include "hole.h"

inherit ROOM;
void create()
{
	::create();
	set_short( "溼地" );
	set_long(@LONG
在這個巨大巖盤之下，竟然是一片十分潮溼的苔地，沼氣瀰漫，
嗆得幾乎都不能呼吸了。洞穴兩旁的青苔也因為缺乏陽光的照射，而
呈現蒼白的顏色，不禁令人懷疑：這裡真的能住人嗎？
LONG
	);
	set( "exits",([
			"north" : HOLE"hole18",
			"southeast" : HOLE"hole20"
			]) );
	reset();
#include <replace_room.h>
}