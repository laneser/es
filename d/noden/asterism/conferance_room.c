// File: /d/noden/asterism/conferance_room.c

#include "asterism.h"
inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("大會議室");
	set_long(
		@C_LONG
這裡是三族最高評議會的大會議室，而這裡也是評議會所定的禁地。
C_LONG
	);
  	set( "light", 1 );
	set( "exits",([
           	        "north" : ASTR"court",
                           "south" : ASTR"underpath",
		      ])  ) ;
	create_door("north","south",([
	            "name"   : "obsidian door",
               "c_name" : "黑曜石大門",
               "keyword": ({ "north door", "obsidian door", "door","gate", }),
	            "c_desc" : "黑曜石大門",
	            "status" : "locked",
	            "lock"   : "ASTERISM_2",
	                             ])
	            ) ;
   create_door("south","north",([
        "name"   : "obsidian door",
        "c_name" : "黑曜石大門",
        "keyword": ({ "south door", "obsidian door", "door","gate", }),
        "c_desc" : "黑曜石大門",
        "status" : "locked",
        "lock"   : "ASTERISM_2",
   ]) );
	reset();
}
