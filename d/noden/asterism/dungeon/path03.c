// File: /d/noden/asterism/dungeon/path02.c

#include "../asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("halfling tower", "下水道的入口");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
    這兒是艾斯特律恩城引以為傲的下水道系統, 站在寬闊的入口, 在讚歎之餘
你不禁懷疑當初是怎樣完成這項工程的。堅實的花崗岩石牆, 寬達數尺的水道, 
讓你覺得這個設施的功能絕對不只是排水而已。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"up" : DUNGEON"paht02",
//                "down":DUNGEON"path03",
		]) );
	reset();
}


