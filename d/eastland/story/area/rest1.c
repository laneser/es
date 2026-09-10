#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("「巫亭」");
	set_long( @LONG
此涼亭名為「巫亭」，乃「巫咸國」第一匠師所造，外型宏觀，內亭富麗，四
周石柱雕工精細，地上種滿靈花異草，芬香馥郁，真乃天下第一亭。涼亭西邊有一
蓮池，水清見底，魚兒悠遊自在，又乃一殊。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	  "out" : SAREA"wiz3",
        ]) );
        set("objects", ([
           "poet#1" : SMOB"poet1",
           "poet#2" : SMOB"poet1",
           "poet#3" : SMOB"poet1",
        ]) ); 
	reset();
}
