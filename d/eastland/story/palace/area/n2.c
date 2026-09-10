#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("殿內長廊");
	set_long( @LONG
這裡是殿內長廊。廊道白玉鋪地，欄杆雕飾精細，朱壁每尺鑲嵌著拳大夜明珠
，好似一條蜿延銀蛇，不時發出白光，照耀著滿道通明。南邊是天都大殿，瓊檻瑤
階，雕雲縷月，氣象莊嚴，奇麗無比；西南是長廊的延伸。
LONG
	);
        set("light",1);
        set("exits" , ([
           "southwest" : SPALACE"x1",
               "south" : SPALACE"n1",
        ]) );
	reset();
}
