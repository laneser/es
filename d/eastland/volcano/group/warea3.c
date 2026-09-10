#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("矮靈族部落");
	set_long( 
@LONG_DESCRIPTION
這裡是矮靈族部落群，西邊可以通到出口，東邊可通到廣場，這裡的建築物大都
是石造的，少數人住帳蓬，地上用很多石板鋪成的路貫穿整個部落，整個部落給人的
感覺是非常寧靜且安詳的，你注意到旁邊有一個掛滿人頭的柱子，當風吹過時，人頭
嘎嘎作響，令人毛股悚然。
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "west" : OGROUP"warea1",
     "southeast" : OGROUP"warea4",
     "northeast" : OGROUP"warea6" ]) );
set( "search_desc",([
     "here":"@@to_search_here",
     ]) );
set_outside("eastland");
reset();
}

string to_search_here()
{
  return  "\n你見到路旁的一根石柱，柱子上有著許多的小洞，幾乎每個小洞都被一條繩子穿過，\n而繩子的另一端，則懸著一顆骷髏頭。\n\n";
}
