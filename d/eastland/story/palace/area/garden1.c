#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("迴廊");
	set_long( @LONG
到了這裡已經是屬於天都後殿了。迴廊地面乃白玉砌成，光滑細潤，不染一點
沙塵；廊道欄杆雕飾精細，廊外瓊枝碧葉，上綴各色繁花，花大如錢或碗，馨香沁
人心脾。北邊是迴廊的延伸，不時傳來泉水鏗鏘有勁之聲。西邊連接著殿內廊道，
東南邊則是通往後花園的小徑。

LONG
	);
        set("light",1);
        set("exits" , ([
                "west" : SPALACE"x4",
               "north" : SPALACE"garden2",
               "south" : SPALACE"garden3"
        ]) );
	reset();
}
