#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("殿內長廊");
	set_long( @LONG
這裡是殿內長廊，長廊往西北方向延伸。廊道白玉鋪地，欄杆雕飾精細，朱壁
每尺鑲嵌著拳大夜明珠，好似一條蜿延銀蛇，不時發出白光，照耀著滿道通明。銜
接東方出口的是迴廊，可以通往後花園。
LONG
	);
        set("light",1);
        set("exits" , ([
                "east" : SPALACE"garden1",
           "northwest" : SPALACE"e2",
        ]) );
	reset();
}
