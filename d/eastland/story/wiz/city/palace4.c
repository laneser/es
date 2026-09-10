#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("皇宮大殿");
	set_long( @LONG
殿前雙金龍搶珠橫踞其上，兩側朱漆畫梁四童子二執寶劍另持羽扇神情莊肅待
立其內，其中一張繡絲爛銀龍背金交椅前面翡玉白階平時城主端於內，殿前武士護
衛文官武臣候立一旁，地上龍鳳呈祥映著水晶天頂，端的是氣派豪華不可而語！在
你東、西邊各有甬道通往內殿。
LONG
	);
        set("light",1);
	set("get_bag",({}));
	set( "exits", ([ 
           "south" : SCITY"palace3",
            "west" : SCITY"road1"
        ]) );
        set("objects", ([
                   "king" : SWMOB"wiz_king1",
            "bodyguard#1" : SWMOB"wiz_bodyguard2",
            "bodyguard#2" : SWMOB"wiz_bodyguard2",
            "bodyguard#3" : SWMOB"wiz_bodyguard2",
        ]) );
	reset();
}
int clean_up()
{  return 0; }