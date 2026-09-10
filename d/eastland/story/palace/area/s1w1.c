#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("天都大殿西南側");
	set_long( @LONG
你立足之地是天都大殿的西南側，大殿地面原是用整片翠精碧玉建成的，玉質
特佳，光明若鏡，毛髮可鑑。環顧殿內，琉璃天瓦，上下兩相對照，發出七彩絢麗
燦光；殿偏玉柱彩繪，朱壁雕樓，除此之外別無它物，雖然空間廣闊，卻益發顯得
莊嚴隆重，氣象萬千，不可而語。
LONG
	);
        set("light",1);
        set("exits" , ([
           "east" : SPALACE"s1",
          "north" : SPALACE"w1",
        ]) );
	reset();
}
