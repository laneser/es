#include "../../story.h"

inherit SPALACE"RR";
inherit DOORS;
void create()
{
        ::create();
	set_short("天都大門");
	set_long( @LONG
你立足之地是天都的大門口，大門寬八尺高三丈，通體用美玉製成，巨門上紋
路變化萬千，雕雲縷月，把此地襯托的更加氣象莊嚴。旁邊一瓊檻瑤階，連接的是
一條白玉小路。東邊是天都的大殿。
LONG
	);
	set("light",1);
        set( "exits", ([
            "down" : SPALACE"plain3",
            "east" : SPALACE"w1"
        ]) );
        set( "objects", ([
           "soldier1" : SPMOB"soldier1",
           "soldier2" : SPMOB"soldier1",
           "soldier3" : SPMOB"soldier1",
            "general" : SPMOB"soldier2",
        ]) );
        create_door( "east","west" ,([
             "keyword" : ({ "jade door", "door" }),
             "name" : "jade door",
             "c_name" : "玉門",
             "c_desc" : "一個白玉做的大門，上面各有兩個碗大的雀環。\n",
             "status" : "closed"
        ]) );
	reset();
}
