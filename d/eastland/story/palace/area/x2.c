#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("殿內長廊");
	set_long( @LONG
這裡是殿內長廊，長廊往這個方向已經是盡頭了。廊道白玉鋪地，欄杆雕飾精
細，朱壁每尺鑲嵌著拳大夜明珠，好似一條蜿延銀蛇，不時發出白光，照耀著滿道
通明。
LONG
	);
        set("light",1);
        set("exits" , ([
           "south" : SPALACE"e2",
        ]) );
	reset();
}
