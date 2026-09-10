#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("北大街");
	set_long( @LONG
你走正走在「巫咸城」內北大街上，大街往東、西方向延伸。由於北大街地處
偏僻，往來無塵囂，街旁樹木稀稀落落於一排排的房子間，空氣清幽，顯的格外清
新脫落，街道內相當安靜，是為居住之地。遙望南邊不遠處有座落一宮殿，那就是
城內最主要的建築物－皇宮，聳立雲端，富麗堂皇，是城民精神上的象徵。往北走
就北門口了。　
LONG
	);
        set("light",1);
	set( "exits", ([ 
            "east" : SCITY"ne2",
       	    "west" : SCITY"nw2",
           "north" : SCITY"northgate",
        ]) );
	reset();
}
