#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("山頂");
	set_long( @LONG
在這山頂四周是層巒疊峰，好似一幕幕的綠布不住往天際延伸。天上白雲離頭
頂只不過尺許高度，一抹抹如條素色的被子，像要壓將下來。往南俯視，與對山之
間銜接著一個溪谷和一座吊橋，那溪流，急湍澎湃，「刷刷」有聲，不知高度若何
，否則大可一遊而盡興。在你東邊是個斷崖，裡面白茫茫的一片，也不知道有多深
，另外在斷崖上還漂著一座浮橋。
LONG
	);
        set("light",1);
	set( "exits", ([ 
              "east" : SAREA"bridge2",
       	      "west" : SAREA"bridge1",
        ]) );
        set("objects", ([
              "god":SMOB"lucky_god"
        ]) );
        set("exit",({"east","west"}));
	reset();
}
