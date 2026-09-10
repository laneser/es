// File: /d/noden/asterism/tower1-6.c

#include "asterism.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("半身人高塔的第六層");
	set_long(
		@C_LONG_DESCRIPTION
這裡是艾斯特律恩城中半身人高塔的最高層第六層.也是半身人族長席藍洛斯十世
(Thilenros X)的住處,四周擺設了很多的奇花異卉(flowers),在平地是無法瞧見的.
C_LONG_DESCRIPTION
	);
       set("c_item_desc",([
           "flowers":"一些奇奇怪怪的奇花異卉,但是卻都是寒帶或高山植物.\n"
           ]) );    	
    	set( "exits", ([ 
		"down":ASTR"tower1-5",
		]) );
	create_door("down","up",([
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
