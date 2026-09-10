#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("山頂");
	set_long( @LONG
在這山頂四周是層巒疊峰，好似一幕幕的綠布不住往天際延伸。天上白雲離頭
頂只不過尺許高度，一抹抹如條素色的被子，像要壓將下來。東邊底下是一白茫茫
的斷崖，也不知道有多深。仰望東北方的天空，漂著一座四方形的建築物。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	      "north" : SAREA"mountain2",
        ]) );
	reset();
}
