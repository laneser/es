#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("殿內長廊");
	set_long( @LONG
這裡是殿內長廊。廊道白玉鋪地，欄杆雕飾精細，朱壁鑲嵌著一串拳大夜明珠
，好似一條蜿延銀蛇，流瑩生輝，照耀著滿道通明。北邊是天都大殿，瓊檻瑤階，
雕雲縷月，氣象莊嚴，奇麗無比。廊道往西北方向延伸。
LONG
	);
        set("light",1);
        set("exits" , ([
           "northwest" : SPALACE"x3",
               "north" : SPALACE"s1",
        ]) );
	reset();
}
