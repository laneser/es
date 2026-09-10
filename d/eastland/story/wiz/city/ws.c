#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("西大街");
	set_long( @LONG
你走正走在「巫咸城」內西大街上，大街往北邊方向延伸，南邊則是南大街。
近來城主有意發展西大街，遂把許多鋪子遷移到這裡來，一時人潮湧洶，販夫走卒
不絕於途，聲勢頗有凌駕東大街之上！由此往北邊可通往西門口，而你右手邊是間
城內最大的藥店。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SCITY"hospital1",
       	   "north" : SCITY"ww",
       	   "south" : SCITY"sw",
        ]) );
	reset();
}
