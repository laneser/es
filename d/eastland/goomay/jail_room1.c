#include "goomay.h"
inherit DOORS;
inherit ROOM;

void create()
{
        ::create() ;
        set_short("牢房" );
        set_long(
@LONG
這裡是捕快們關犯人的地方，犯了案的犯人都關在這裡，簡簡單單的
牢房裡只有一張稻草鋪成的床，牢房中充斥著黴腐與死亡的氣息，。這裡
黑黝黝的，空氣又差，你真想趕快出去。
LONG
        );
        
        set( "exits", ([ 
		"south" : Goomay"jail",
        ]) );
        set( "objects", ([
                "prisoner1" : Mob"prisoner1",
                "prisoner2" : Mob"prisoner1",
        ]) );
        
        set("c_item_desc",(["bed":"一張簡單的稻草床。\n" ]));

      create_door("south","north",
            ([  "keyword" : ({"door","gate"}),
                "name"    : "Iron door",
                "c_name"  : "鐵柵門",
                "c_desc"  : "這是一扇有著粗大鐵欄的鐵柵門",
                "status"  : "open",
                "lock"    : "JAIL_DOOR",
                ]) );

        reset();

}

