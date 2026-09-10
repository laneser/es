// File: /d/noden/asterism/tower1-3.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("半身人高塔的第三層");
	set_long(
		@C_LONG_DESCRIPTION
這裡是艾斯特律恩城中半身人高塔的第三層,一種快樂的氣氛感染了你的心頭,在
半身人無可救藥的樂天派的影響下,他們認為一層的防衛措施已經足夠,因此這裡天天
都在開宴會,充滿著歡笑的聲音.
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"up" : ASTR"tower1-4",
		"down":ASTR"tower1-2",
		]) );
	set("objects",([
	     "explorer":MOB"halfling_explorer",
	     ]) );
	reset();
#include "replace_room.h"
}
