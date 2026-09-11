
#include "goomay.h"

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
	set_short("地洞");
	set_long( @LONG_DESCRIPTION
你現在來到一個陰暗的地洞，空氣似乎一點也不潮溼，還帶著一絲絲熱氣，
一點也不像一般的地洞，黝黑的洞壁好像是被火焰燒灼過，幽幽地反射著你的
火把的微光。
LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"south" : Goomay"cellar2", 
		"up"    : Goomay"blacksmith" ]) );
        set( "objects", ([
                "rat1" : "/d/noden/farwind/monster/rat",
                "rat2" : "/d/noden/farwind/monster/rat",
        ]) );

	create_door( "south", "north", ([
		"keyword" : ({ "steel door", "door" }),
		"name" : "steel door",
		"c_name" : "鋼門",
		"c_desc" : @C_DESC
這是一扇由精鋼鑄成的門，厚重結實的門上雖然佈滿了灰塵蛛絲，
但是當年精□的純鋼仍然在微弱的火光下倔強地泛出閃閃的輝光，門的
左上角鐫著一個紅色下凹的印記－一個火焰的記號，同時你也注意到，
印記下刻著一行大字：

	擅	啟	此	門	者	死

C_DESC
,		"status" : "locked",
		"lock" : "FIRE_ELEMENT_KEY"
	]) );
	reset();
}
