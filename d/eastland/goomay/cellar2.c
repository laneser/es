
#include <goomay.h>

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
	set_short("地洞");
	set_long( @LONG_DESCRIPTION
你現在正位於一條陰暗的通道中，這條通道佈滿了許多煤渣和炭灰，
通道兩旁則規律地排放著一方方的火爐和鐵□，這裡原來可能是一個鐵工廠
，從地面上四處亂丟的工具看來，原來的主人似乎走的很匆忙，而且再也不
曾回來過。這裡沒有任何的透氣孔，可是不知道從哪裡來的熱風一陣陣地吹
來，你感覺燠熱難耐....
LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : Goomay"cellar1" ,
                "south" : Goomay"cellar3" ,
                "east" : Goomay"cellar4" ,

	]) );

	create_door( "north", "south", ([
                "keyword" : ({ "steel door", "door" }),
                "name" : "steel door",
                "c_name" : "鋼門",
                "c_desc" : @C_DESC
這是一扇由精鋼鑄成的門，厚重結實的門上雖然佈滿了灰塵蛛絲，
但是當年精□的純鋼仍然在微弱的火光下倔強地泛出閃閃的輝光。
C_DESC
,		"status" : "locked",
                "lock" : "FIRE_ELEMENT_KEY"
        ]) );

	reset();
}

