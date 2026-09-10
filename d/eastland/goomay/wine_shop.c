#include "goomay.h"
#include <money.h>

inherit ROOM;
inherit "/std/seller";

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short("趙燕居大酒樓" );
        set_long(
@LONG
這裡是古梅鎮最大的酒樓，粉金彩銀的裝潢洋溢著一股富貴安樂的氣息，
排滿一張張八仙桌的大堂上現在正擠的水洩不通，幾名店小二忙進忙出的
顯得十分熱鬧，櫃檯後一個留著八字小胡的掌櫃笑咪咪的和每一個客人打
招呼。暢飲趙燕居的美酒一向是各路英雄來到古梅鎮的目的之一，如果你
有興暢飲，可以先問問價錢(menu)。
LONG
        );
        
        set( "exits", ([ 
        	"west"  : Goomay"mgate" ,
		"north" : Goomay"row13",
		"up"    : Goomay"wine_shop2",
        ]) );
        
        set_inventory( ({
                       ({ "/d/noden/farwind/items/ching.c",10,10}),
                       ({ "/d/noden/farwind/items/xo.c",10,10}),
                       ({ "/d/noden/farwind/items/rose.c",10,10}),
                       }) );

        set( "objects", ([
                "shop owner" : Mob"wine_owner",
                "girl"       : Mob"tang_ying",
        ]) );
        reset();
}

void reset()
{
     room::reset() ;
     seller::reset() ;
     return ;
}
