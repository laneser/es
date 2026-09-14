#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("六角涼亭");
	set_long( @LONG
你身處在湖中一座古色古香的六角涼亭裡，亭外湖面蕩蕩，碧波鱗鱗。涼亭玉
柱朱庭，四面綠杆欄楣，周圍繁卉，其花如碗，多為鮮豔欲滴，撲人香氣，沁人人
脾；花外更圍著一圈二尺高的珊瑚朱欄，環繞若寶石項鍊，吃繁花一襯，益發貴氣
十足，此乃涼亭一絕。亭旁一座水晶拱橋，雕鏤精細，銀光閃閃，耀眼生輝。

LONG
	);
        set("light",1);
        set("exits" , ([
             "bridge" : SPALACE"bridge2",
        ]) );
        set("objects", ([
           "servant#1" : SPMOB"f_se1",
           "servant#2" : SPMOB"f_se1",
           "servant#3" : SPMOB"f_se1",
               "queen" : SPMOB"queen1"
        ]) ); 
	reset();
}
