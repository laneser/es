#include <mudlib.h>

inherit DOORS;
inherit ROOM;

void create()
{
        ::create();
        set_short("時空隧道");
        set_long( @C_LONG_DESCRIPTION
一個去白魔法城的時空隧道。
C_LONG_DESCRIPTION
        );

        set( "exits", ([ 
                "west" : "/d/mage/tower/white_lib", 
                "south" : "/d/mage/tower/time1" ]) );
        create_door( "west", "east", ([
                "keyword" : ({ "rusty iron door", "iron door", "door" }),
                "name" : "rusty iron door",
                "c_name" : "白魔法之門",
                "c_desc" : "一扇有魔力的白色門",
                "status" : "locked",
                "lock" : "1"
        ]) );
        reset();
}
