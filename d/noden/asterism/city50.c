// File: /d/noden/asterism/city50.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("觀察站");
	set_long(
		@C_LONG_DESCRIPTION
這裡是艾斯特律恩(asterism)城的觀察站,這裡除了南邊回到城裡以外,其它的
三邊都是深不見底的懸崖,所以從這裡能清楚的看到所有從山下上來的人,因此這裡
被建成一個前哨站,為艾斯特律恩城防衛網的第一線。
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
	set( "light", 1 );
        set("objects",(["sentry#1":MOB"dwarf_sentry",
                        "sentry#2":MOB"dwarf_sentry",
                ]) );
                        
	set( "exits", ([ 
		"south" : ASTR"city51",
		]) );
	reset();
#include "replace_room.h"
}
