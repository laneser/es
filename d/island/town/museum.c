#include "../island.h"

inherit ROOM;

void create()
{
	::create();
	set_short("和平紀念堂");
	set_long(@C_LONG
這兒就是和平紀念堂的一樓，中間佇立的石碑就是著名的『停戰紀念
碑』。這個碑的形狀有點像是一把長柄武器，插在這裡的意義代表著「幹
戈止於此地」。二樓是管理中心，還有史蹟陳列室。
C_LONG
		);
	set("light",1);
	set("exits",([
                 "east" : ITOWN"square07",
                 "west" : ITOWN"square03",
               "south"  : ITOWN"square05",
               "north"  : ITOWN"square01",
                 "up"   : ITOWN"museum01"
            ]) );
        set("objects",([
                 "stone":IOBJ"stone"
                 ]));      
	reset();
}
