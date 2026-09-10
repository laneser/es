// File: /d/noden/asterism/lib01.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("圖書館大廳");
	set_long( 
		@C_LONG_DESCRIPTION
這裡是艾斯特律恩(asterism)城的圖書館大廳。當初與魔族一戰曾將這個
圖書館幾乎摧毀殆盡。但在半身人的巧手之下，新的建築讓人感覺和文藝復興
時期的巴洛克式建築頗有神似處。牆上掛著一幅幅的畫。空曠大廳中的參觀者
寥寥可數，但是每個人都很尊重這裡肅穆的氣氛而儘量輕聲細語。這兒僅有的
聲響是你回湯在這空間中的腳步聲。
C_LONG_DESCRIPTION
	);

//	set_outside( "asterism" );
	set( "light", 1 );
        set("c_item_desc",(["paintings":
             "一幅幅令人感到炫目的畫，仔細一看全部都是用各色寶石鑲成的.\n"]));       
	set( "exits", ([ 
		"out"  :ASTR"city_library",
		"north":ASTR"lib_n",
		"south":ASTR"lib_s",
		"west" :ASTR"lib_w",
		]) );
	reset();
#include "replace_room.h"	
}                         

