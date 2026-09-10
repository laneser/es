#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("天都大殿東側");
	set_long( @LONG
你立足之地是天都大殿的東側，大殿地面原是用整片翠精碧玉建成的，不但玉
質特佳，光明若鏡，毛髮可鑑。環顧殿內，琉璃天瓦，上下兩相對照，發出七彩旋
轉虹光；殿偏玉柱彩壁，左側一金門矗立，除此之外別無它物，雖然空間廣闊，卻
益發顯得莊嚴隆重，氣象萬千。
LONG
	);
        set("light",1);
        set("exits" , ([
           "east" : SPALACE"e2",
           "west" : SPALACE"center",
          "north" : SPALACE"n1e1",
          "south" : SPALACE"s1e1",
        ]) );
	reset();
}
