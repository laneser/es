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
       	      "east" : SAREA"village2" 
        ]) );
        set( "objects", ([
           "adult#1" : SMOB"adult1",
           "woman#1" : SMOB"woman1",
           "older#1" : SMOB"older1",
           "older#2" : SMOB"older1",
        ]) );
	reset();
}
