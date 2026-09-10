#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("殿內長廊");
	set_long( @LONG
這裡是殿內長廊。廊道白玉鋪地，欄杆雕飾精細，朱壁每尺鑲嵌著拳大夜明珠
，好似一條蜿延銀蛇，不時發出白光，照耀著滿道通明。西邊是天都大殿，瓊檻瑤
階，雕雲縷月，氣象莊嚴，奇麗無比；長廊往西南、北方向延伸。
LONG
	);
        set("light",1);
        set("exits" , ([
               "west" : SPALACE"e1",
              "north" : SPALACE"x2",
          "southeast" : SPALACE"x4",
        ]) );
	reset();
}
