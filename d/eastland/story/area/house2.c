#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("屋子");
	set_long( @LONG
這裡是羽民族小屋，平時羽民族住的地方。屋子有木製成的桌子、椅子和一張
床，以及一簍簍裝滿著剛採下來和曬乾的葡萄的大型籃子。小屋收拾的一塵不染，
雖然是些簡單的擺設，對於生性不華麗的羽民族來說，已經足夠了。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	      "east" : SAREA"village1" 
        ]) );
        set( "objects", ([
           "older#1" : SMOB"older1",
           "older#2" : SMOB"older1",
           "older#3" : SMOB"older1",
        ]) );
	reset();
}
