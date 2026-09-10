#include "farwind.h"
#include <money.h>

inherit ROOM;
inherit "/std/seller";
inherit DOORS;

void create()
{
        ::create() ;
        set("light", 1) ;
   set_short( "遠風書店" );
   set_long(
@LONG
這裡是遠風鎮唯一的書店，也是整個諾頓大陸上最大的書店。
當你一走了進來，你感到一股書香的氣息。你左手(left)邊的書架
上擺了一排的小說，右手(right )邊則是一些古典文學類的書。而
擺在櫃檯(table )上的，是一些最近的暢銷書籍。
LONG
       );
        
        set( "exits", ([ 
        	"south" : FARWIND"bazz2" ,
        ]) );
        
        set_inventory( ({
                       ({ "/d/noden/farwind/items/book.c",10,10}),		       			
        }) );
        create_door("south","north",
		 ([  "keyword" : ({"wooden","door"}),
		     "name"    : "wooden door",
		     "c_name"  : "木門",
		     "c_desc"  : "這是一扇可愛的小木門，門上掛了一個書店的招牌",		
		     "status"  : "open",
		]) );
	set("c_item_desc",([
		"left" : 
"你看到書架上空空如也，什麼都沒有...\n"
		,"table" : 
"你只看到一本名為『東方故事集(story)』的書，其他什麼書都沒有...\n"
		,"right" : 
"你看到書架上空空如也，什麼都沒有...\n"
		])	);		 	
        set( "objects", ([
                "shop owner" : "/d/noden/farwind/monster/book_owner",
        ]) );
        reset();
}

void reset()
{
	room::reset();
	seller::reset();
}
