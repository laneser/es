#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("北大街");
	set_long( @LONG
你走正走在「巫咸城」內北大街上，大街往西邊方向延伸，南邊則是東大街。
由於北大街地處偏僻，往來無塵囂，街旁樹木稀稀落落於一排排的房子間，空氣清
幽，顯的格外清新脫落，街道內相當安靜，是為居住之地。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "west" : SCITY"ne2",
       	   "south" : SCITY"en1"
        ]) );
	reset();
}
