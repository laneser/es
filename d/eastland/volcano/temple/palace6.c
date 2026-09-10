#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
	::create();
	set_short( "龍王寢宮" );
	set_long(
@LONG
這裡是龍王的寢宮，整個房間散發出柔和的光芒，一張用象牙撐起大床，
被子看不出是用什麼質料縫製而成，但一定相當輕且柔軟，牆壁上掛著一
幅畫乃是出自天下第一丹青手－－沈雙雙之手，地上鋪著厚厚的地毯，房
間中還擺了一盆罕見的碧玉香，據說是菊花的一種。
LONG
	);
	set( "exits", ([
	     "south" : OTEMP"palace4",
	]) );
        set("objects",([
            "dragon_king":OMONSTER"dragon_king",
            ]) );
         set("light",1);
         reset(); 
}
