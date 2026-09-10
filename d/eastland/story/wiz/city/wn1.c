#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("西大街");
	set_long( @LONG
你走正走在「巫咸城」內西大街上，大街往南邊方向延伸，北邊則是北大街
，東邊則是城中心道路，許多皇室貴族都居住在那裡，往南走可達西門口。近來
西大街有凌駕東大街的趨勢，日益繁華，街旁多是一排排的商鋪。
LONG
	);
        set("light",1);
	set( "exits", ([ 
            "east" : SCITY"nw1",
           "south" : SCITY"ww",
           "north" : SCITY"wn2",
        ]) );
	reset();
}
