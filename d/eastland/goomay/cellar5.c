
#include "goomay.h"

inherit ROOM;

void create()
{
	::create();
	set_short("地洞");
	set_long( @LONG_DESCRIPTION
你現在正位於一條陰暗的通道中，這條通道佈滿了許多煤渣和炭灰，
通道兩旁則規律地排放著一方方的火爐和鐵砧，這裡原來可能是一個鐵工廠
，從地面上四處亂丟的工具看來，原來的主人似乎走的很匆忙，而且再也不
曾回來過。這裡沒有任何的透氣孔，可是不知道從哪裡來的熱風一陣陣地吹
來，你感覺燠熱難耐....
LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : Goomay"cellar4" ,
		"west" : Goomay"cellar6" ,
	]) );
	set( "objects", ([
	"fire_element" : Mob"fire_beast", ]) );
        set("exit_suppress", ({ "west" }) );
	set("pre_exit_func",([   "west"  :  "to_pass" ]) );
        ::reset();
}

int to_pass()
{
   if ( !(this_player()->query_temp("fire_element")) ) {
     write("一道魔法牆阻擋住你的去向.\n");
     return 1;
   }
   else {
     write("由於你的身體有著一股神奇的力量,你輕易的通過魔法牆.\n");
     return 0;
   }
}
