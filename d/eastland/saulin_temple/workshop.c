#include "saulin_temple.h"

#include <money.h>

inherit "/std/shop";

void create()
{
	::create() ;
	set("light", 1) ;
	set_short( "惜物工房" );
	set_long( @C_LONG
你走進了一個工作坊，四周吵雜的各種響聲亂成一片，幾名僧人正製作著各
種不同的器具－銅燈、燭臺，甚至兵器、禪杖。後面還有人在縫製僧衣，看來整
個少林寺的日常用品都是由這裡製造的。一名老僧(old monk)站在眾僧之中監督
著他們工作，他應該是這裡的負責人。
C_LONG
);
    set( "item_desc",([ "monk" : @C_LONG
你仔細打量那位老僧，他突然回頭對你點頭笑笑，並向你合十道：

  阿彌陀佛! 施主可是來參觀的嗎？歡迎之至，本工房專門負責寺中一切器物
  的修理(fix) 、製造(make)，也接受施主們的工作委託。同時我們負責舊貨
  的回收再利用，你可以在這裡買(buy) 、賣(sell)物品。本工作坊一切營利
  所得完全用於濟助貧苦，歡迎施主共襄盛舉。
  
C_LONG
    ]));
// rating 1,5 mean 1/5 Because monk is no money!
    set("rating", ({ 1, 5 }));
	set( "exits", ([ 
	     "south" : SAULIN"kitchen2", 
	]) );
	::reset();
}
