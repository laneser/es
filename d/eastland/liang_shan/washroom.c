#include "takeda.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "洗衣房" );
	set_long(
	"這裡是梁山泊的洗衣房，目前的大王宋江，認為寨內不可有人\n"
	"不事生產．因此，寨內一部份的婦女，在此清洗所有的衣物．角落\n"
	"有一口水井(well)．\n"
	  
	);
	set( "light",1 );
        set("c_item_desc",(["well":
"根據你多年來的直覺，你認為一定可以爬下去，而且下面一定有青蛙．\n"
            ]));        
        set( "objects", ([
             "boss" : TMONSTER"pang",
             "lady1" : "/d/eastland/goomay/monster/poor_woman",
             "lady2" : "/d/eastland/goomay/monster/poor_woman"
             ]));
        set( "exits", ([
                "north" : TROOM"path3",
                "south" : TROOM"dryroom"
        ]) );
        reset();
}
int clean_up() { return 0; }
/*
void init()
{
     add_action("do_climb","climb");
}
int do_climb(string arg)
{
if (!arg || arg !="well")
return notify_fail(
"爬什麼\n");
write (
"還沒做好...:)\n");
} 
*/    