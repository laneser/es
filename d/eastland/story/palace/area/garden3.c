#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("玉石小徑");
	set_long( @LONG
玉石小徑延伸逾數十里長，通體紅玉鋪成，質若明晶，兩旁均是參天花樹，因
為樹大枝繁，上面花枝糾結連成一片，一眼望去，直似兩條花龍錦城，蜿蜓飛舞。
近距離狎玩，花樹翠幹銀枝，瓊花玉葉，姹紫嫣紅，縈青儷白，其大如鬥，競吐芳
菲。東北邊是條白玉迴廊。

LONG
	);
        set("light",1);
        set("exits" , ([
                "north" : SPALACE"garden1",
           "southeast" : SPALACE"garden4",
        ]) );
	reset();
}
