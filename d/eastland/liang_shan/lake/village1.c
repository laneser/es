#include "takeda.h"
#include <move.h>
#include <stats.h>
#include <conditions.h>

inherit ROOM;

int fish_present = 1;

void create()
{
	::create();
	set_short( "石碣村" );
	set_long(
	"這裡是梁山泊外的小漁村－石碣村，村中居民並不多，大約只有\n"
	"五六家，家家門口都曬著許多魚網(net)或漁具，也許這兒的居民通通\n"
	"都靠打漁維生。\n"
	  );
	set_outside("eastland");
        set("c_item_desc",(["net":
"這些是再普通不過的魚網，這兒的居民們利用它來捕捉湖中的水產以維\n"
"持生計。你仔細觀察這些魚網，在其中一張魚網的中間，好像纏著什麼東西?\n"
            ]));        
        set( "exits", ([
                "south" : TROOM"beach8",
                "north" : TROOM"village2",
                "west"  : TROOM"room2"
        ]) );
        reset();
}
void init()
{
     add_action("do_search","search");
}
int do_search(string arg)
{
 object fish1,fish2,fish3;
 if ( !arg || arg != "net")
    return notify_fail(
    "要找什麼?\n");
	if( !fish_present )
		write(
		    "你把魚網翻過來翻過去，什麼都沒發現，你想你可能看錯了。\n"
		);
	else {
		write(@ALONG
你發現魚網中間纏著幾隻小魚，你把它從魚網上解下來，放在鼻子前聞了一下，
哇，這味道讓你暫時失去思考的能力，體力好像也變弱了.....
ALONG
		);
		fish_present = 0;
		fish1 = new( "/d/eastland/liang_shan/obj/rotten_meat" );
		fish2 = new( "/d/eastland/liang_shan/obj/rotten_meat" );
		fish3 = new( "/d/eastland/liang_shan/obj/rotten_meat" );
		if( (int)fish1->move(this_player()) != MOVE_OK )
			fish1->move( this_object() );
	        if( (int)fish2->move(this_player()) != MOVE_OK )
	                fish2->move( this_object() );
	        if( (int)fish3->move(this_player()) != MOVE_OK )        
	                fish3->move( this_object() );
	        (CONDITION_PREFIX + "weak")->apply_effect(this_player(),4,4);
	        return 1;
	}
}
