#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("地下通道");
	set_long(
@C_LONG_DESCRIPTION
你現在來到一個寬闊的地下通道，四周的牆壁是用上好石磚砌成的，地上積了一層淺淺
的灰，似乎已經有好一段時間沒有人進來過。通道深處吹來一陣陣的冷風，你的經驗告訴你
必須打醒十二萬分的精神來面對未知的危險。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"east" : TOMB"/maze8",
		"west" : TOMB"/maze6",
		"north" : TOMB"/maze6", 
		"south" : TOMB"/maze6" ]) );
	reset();
#include <replace_room.h>
}

