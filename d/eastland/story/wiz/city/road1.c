#include "../../story.h"

inherit ROOM;
inherit DOORS;
void create()
{
        ::create();
	set_short("內殿甬道");
	set_long( @LONG
你正走在皇宮殿內的一條長數十尺的甬道上。這甬道雕樑畫柱、瑤階翠檻，珠
光寶氣，耀眼生輝。兩旁百盞琉璃瑩燈，五花撩亂，全道通明，有如白晝；北邊一
間偏室是鐵扇公主的居所，通體碧玉砌成，金門翠東，富麗堂皇，神仙宮室，不過
如斯。
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "east" : SCITY"palace4",
          "north" : SCITY"house4"
        ]) );
        create_door( "north", "south", ([
          "keyword" : ({ "golden door", "door" }),
          "name" : "golden door",
          "c_name" : "金門",
          "c_desc" : "一個金澄澄的大門，上面各有兩個雀環。\n",
          "status" : "closed"
        ]) );
	reset();
}
