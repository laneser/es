#include "iigima.h"
inherit ROOM;
inherit DOORS;

void create()
{
        ::create();
        set_short( "gate","禁地之門");
        set_long(
@C_LONG
這裡是黑暗精靈村的禁地，前方傳來陣陣的奇怪聲響，以及哀嚎聲
你必須拿出萬全的心裡準備，因為，不知名的恐怖可能隨時會到來。
C_LONG
        );

        set( "exits", ([
                   "northeast": DROW"r37",        
                   "south": DROW"r04",
        ]) );
        create_door( "south", "north", ([
                "keyword" : ({ "iron door", "door" }),
                "name" : "iron door",
                "c_name" : "大鐵門",
                "c_desc" : "一扇冷冰冰的鐵門。\n",
                "status" : "locked",
                "lock" : "IRON_DOOR"
        ]) );         
}
