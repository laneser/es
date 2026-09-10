#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("浮橋");
	set_long( @LONG
你站在浮橋上往四周觀望，底下是一片白茫茫的斷谷，不知道有多麼深；北方
的遠處是層巒疊峰，一幕幕的綠布不住地往天際延伸；抬頭一望，白雲只不過離頭
頂數尺高度；而東邊是山頂，據說，巫咸國由此而去。
LONG
	);
        set("light",1);
        set( "exit_suppress", ({
	     "hole"}) );
	set( "exits", ([ 
               "east" : SAREA"wiz1",
       	       "west" : SAREA"mountain4",
        ]) );
        set("exit",({"east","west"}));  
	reset();
}
