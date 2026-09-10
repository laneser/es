#include <mudlib.h>

inherit ROOM;
inherit "/d/scholar/train";

void create()
{
	::create();
    set_short("Gonfu room", "功夫室");
	set_long( @LONG_DESCRIPTION
This is the inner hall of scholar's guild. .
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
你在進入了書生公會內部的功夫室，這裡是書生們習武的地方，只有書生
公會的人才能進來，大廳中央有一本記載武功心法的書(book)。
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "book":@BOOK
書上有寫著一些武功心法如果你想學的話可以用 train <功夫名稱> 學得。

護體神功 ： 布衣神功(booyi)
輕功     ： 天羅步(tanlo)
運功心法 ： 運功療傷(force-heal)    
劍術     ： 無名劍法(unknow)

BOOK
	]));         
	set( "light", 1 );
	set( "exits", ([ 
		"south" : "/d/scholar/scholar/scholar_inner" ]) );
    set_gonfus(([
          "tanlo"        : ({  3 ,  1000 }),
          "force-heal"   : ({  6 ,  3000 }),
          "booyi"        : ({  8,   8000 }),
          "unknow"       : ({ 10 , 15000 }),
	]));
	reset();
}
