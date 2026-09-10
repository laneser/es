// File: /d/noden/asterism/tower1-5.c

#include "asterism.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("半身人高塔的第五層");
	set_long( 
		@C_LONG_DESCRIPTION
這裡是艾斯特律恩城中半身人高塔的第五層,空空蕩蕩的是這房間的特色.其實這
裡是魔法師的冥想室.因此這裡非常的寂靜.在往上一層就是半身人族長的房間了.
C_LONG_DESCRIPTION
	);

    	set("objects",([
    	    "redmage":MOB"halfling_mage01",
    	    "blackmage":MOB"halfling_mage02",
    	    ]) );
    	set( "exits", ([ 
		"up" : ASTR"tower1-6",
		"down":ASTR"tower1-4",
		]) );

	create_door("up","down",([
             "name":"white door",
             "c_name":"白色的門",
             "keyword":({"white door","door",}),
             "c_desc":"白色的門",
             "status":"locked",
             "desc":"a white door",
             "lock":"ASTERISM_1",
                     ]) );
	reset();
}
