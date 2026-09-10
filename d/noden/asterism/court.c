// File: /d/noden/asterism/court.c

#include "asterism.h"

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
	set_short("會議室前大廳");
	set_long(
		@C_LONG_DESCRIPTION
這裡是三族長老評議會會議室前的廣場，三族平時各事其政，除有緊急
事件發生外，三族長老只有在每年"聖戰紀念日"時，才會結合"永恆之鑰"
打開會議室大門。
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
                    "south"  : ASTR"conferance_room",
		"north"  : ASTR"tower3-0",
		]) ) ;
		
	create_door("south","north",([
	            "name":"obsidian door",
                    "c_name":"黑曜石大門",
	            "keyword":({"obsidian door","door",}),
	            "c_desc":"一面黑曜石大門。"
	                     "你注意到在兩扇門的中間接縫處有塊三角形凹槽",
	            "status":"locked",
	            "lock":"ASTERISM_2",
	                         ])
	            ) ;
	                         
	reset();
}
