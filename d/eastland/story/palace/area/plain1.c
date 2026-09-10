#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("天台");
	set_long( @LONG
你正立足在一塊小小的玉製橢圓形平臺上，四周遍是綠油油的草地，天空無垠
的蒼穹。在這天台旁有幾尊刻工精美的白玉雕像，尊尊羽衣星冠，丰神俊郎，衣服
華美，栩栩如生望若神仙中人。遙望東邊，一宮院金庭玉柱，瑤壁瓊樓，富麗□皇
，氣象萬千，不可而語。在臺下有階梯通往東方草地上的一條小路。
LONG
	);
	set("light",1);
	set("can_use_flute",1);
        set( "exits", ([
            "steps" : SPALACE"plain2"
        ]) );
	reset();
}
