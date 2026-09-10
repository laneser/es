#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("城中心道路");
	set_long( @LONG
這裡是「巫咸國」的中心道路，同時也是達官貴人居住的地方。地是用玉做的
，並且在玉上還雕刻著龍鳳之類的祥瑞動物，把北邊一座座氣派豪華的建築物襯托
的更加富麗堂皇。另外在南邊的路旁還建造一個噴水池，其雕工精美，不亞於地上
所刻的動物。東邊是城中心，西邊是西大路，南邊有一間錢莊。
LONG
	);
        set("light",1);
	set( "exits", ([ 
             "east" : SCITY"center",
             "west" : SCITY"wn1",
            "south" : SCITY"bank1"
        ]) );
        set( "objects", ([
           "policeman#1":SWMOB"wiz_guard2",
           "policeman#2":SWMOB"wiz_guard2",
           "policeman#3":SWMOB"wiz_guard2",
        ]) );
	reset();
}
