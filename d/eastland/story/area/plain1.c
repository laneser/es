#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("草原");
	set_long(@LONG
你來到了一處空曠的草原，東和北邊是草原的延伸而南邊是大樹群。在草原上
長滿了些小小的矮花，矮花的顏色很鮮豔，靠近一聞，鼻子中滿是濃郁的香味。除
此之外，一群野蜂正悠哉悠哉地穿梭在花叢間，恣意地採著蜂蜜。另外在你西邊長
滿了高及頭頂的植物，裡面不時傳來野獸的叫聲，那聲音令你感到毛骨悚然，你心
裡想想，最好還是不要往那邊走去，以免發生危險。
LONG
	);
	set("light",1);
	set("exits", ([ 
            "east" : SAREA"plain2",
            "west" : SAREA"coast6",
           "north" : SAREA"plain3"
        ]) );
	reset();
}
