#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("大國師官邸");
	set_long( @LONG
這裡是「巫城國」護國師居住的官邸。官邸裡雕樑畫棟，琉璃天頂，彩壁朱繪
，白銀器皿，珊瑚制椅具，前面一張虎背玉座，後面八駿馬屏風，端的是一脈珠光
寶氣，金碧輝煌不可而語。旁邊各有甬道可以通往內堂。
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "out" : SCITY"ne1"
        ]) );
        set( "objects", ([
           "elder" : SWMOB"wiz_elder1",
        ]) );
	reset();
}
