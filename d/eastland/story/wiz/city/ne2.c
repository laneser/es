#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("北大街");
	set_long( @LONG
你走正走在「巫咸城」內北大街上，大街往東、西方向延伸。由於北大街地處
偏僻，往來無塵囂，街旁樹木稀稀落落於一排排的房子間，空氣清幽，顯的格外清
新脫落，街道內相當安靜，除了一兩童女追逐嬉戲外，是為居住之地。往西走可以
到達北門口。
LONG
	);
        set("light",1);
	set( "exits", ([ 
            "east" : SCITY"en2",
       	    "west" : SCITY"nn",
        ]) );
	reset();
}
