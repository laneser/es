// File: /d/noden/asterism/lib_w.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("Office of library administer", "圖書館館長室");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
這個房間的佈置蠻簡樸的，偌大的房間中央擺了一張大大的辦公桌。
四壁牆上掛了不下十幅的畫，這是這個單調房間中唯一的點綴。
C_LONG_DESCRIPTION
	);

//	set_outside( "asterism" );
	set( "light", 1 );
        set("c_item_desc",(["paintings":
             "一幅幅令人感到炫目的畫，仔細一看全部都是用各色寶石鑲成的.\n"
             "用寶石能“畫”出肖像畫，這種技術真是可怕。\n"]));       
	set( "exits", ([ 
		"east" :ASTR"lib01",
		]) );
//	set( "objects","Administer" : MOB"lib_adm" , ) ;
	
	reset();
	
}                         

