//#pragma save_binary

#include "/d/noden/farwind/farwind.h"
#include <money.h>

inherit ROOM;
inherit "/std/seller";
inherit DOORS;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "小酒店" );
        set_long(@C_LONG
這裡是遠風鎮最有名的酒店，長久以來，冒險家們在這裡
休息，互相換取著比金錢還寶貴的經驗。遊吟詩人在輕輕著唱
著古老的旋律，火爐中的火燒得正烈。這時，沒有什麼比來一
杯烈酒更好的了。老經驗的人都知道這裡賣些什麼，不過你還
是可以跟老闆娘要份菜單(menu)來看看!
C_LONG
        );
        
        set( "exits", ([ 
        	"south" : FARWIND"bazz1" ,
        ]) );
        set_inventory( ({
                       ({ FARWIND"items/ching.c", 10, 10}),
                       ({ FARWIND"items/xo.c", 10, 10}),
                       ({ FARWIND"items/rose.c", 10, 10}),
					   ({ FARWIND"items/vodka.c", 10, 10}),
					   ({ FARWIND"items/chicken.c", 10, 10}),
					   ({ FARWIND"items/special.c", 20, 20}),
        }) );
        create_door("south","north",
		 ([  "keyword" : ({"wooden","door"}),
		     "name"    : "wooden door",
		     "c_name"  : "木門",
		     "c_desc"  : "這是一扇可愛的小木門，門上掛了一個酒店的招牌",		
		     "status"  : "open",
		]) );

        set( "objects", ([
                "shop owner" : FARWIND"monster/wineshop_owner",
                "drunk": FARWIND"monster/drunk"
        ]) );
        reset();
}

void reset()
{
     room::reset() ;
     seller::reset() ;
     return ;
}
