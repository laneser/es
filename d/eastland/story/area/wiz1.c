#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("山頂");
	set_long( @LONG
在這山頂北方的遠處是層巒疊峰，好似一幕幕的綠布不住往天際延伸。西邊底
下是一白茫茫的斷谷，也不知道有多深，另外在斷谷上有一座浮橋。抬頭一望，頭
上的白雲只不過離頂尺許高度，宛如一條素色的被子，像要壓將下來。在東北邊有
條蜿延崎嶇的小路，據說，可以由此通往巫咸國。
LONG
	);
        set("light",1);
        set( "exit_suppress", ({
            "ned"}) );
	set( "exits", ([ 
       	     "northeastdown" : SAREA"wiz2",
                       "ned" : SAREA"wiz2",
                      "west" : SAREA"bridge2"
        ]) );
	set("exit",({"west"}));
	reset();
}
