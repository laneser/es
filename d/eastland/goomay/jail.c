#include "goomay.h"

inherit DOORS;
inherit ROOM;

void create()
{
        ::create() ;
        set_short( "大牢" );
        set_long(
@LONG
這裡是捕快們關犯人的地方，犯了案的犯人都關在這裡，一條簡單的
長廊兩旁都是牢房，當你走過時，牢裡的犯人都用一種憎惡的眼光看著你
，甚至伸出枯瘦的手來抓你。這裡黑黝黝的，空氣又差，你真想趕快出去。
LONG
        );
        
        set( "exits", ([ 
		"east" : Goomay"jail",
                "west" : Goomay"police",
		"north" : Goomay"jail_room1",
		"south" : Goomay"jail_room2",
        ]) );
      create_door("west","east",
            ([  "keyword" : ({"gate"}),
                "name"    : "Iron gate",
                "c_name"  : "鐵柵門",
                "c_desc"  : "這是一扇有著粗大鐵欄的鐵柵門",
                "status"  : "locked",
                "lock"    : "JAIL_DOOR",
                ]) );

      create_door("north","south",
            ([  "keyword" : ({"north door","door"}),
                "name"    : "Iron door",
                "c_name"  : "鐵柵門",
                "c_desc"  : "這是一扇有著粗大鐵欄的鐵柵門",
                "status"  : "locked",
                "lock"    : "JAIL_DOOR",
                ]) );

      create_door("south","north",
            ([  "keyword" : ({"south door","door"}),
                "name"    : "Iron door",
                "c_name"  : "鐵柵門",
                "c_desc"  : "這是一扇有著粗大鐵欄的鐵柵門",
                "status"  : "locked",
                "lock"    : "JAIL_DOOR",
                ]) );
        
        reset();
}

