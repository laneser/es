#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("西大街");
	set_long( @LONG
你走正走在「巫咸城」內西大街上，大街往北、南方向延伸，西邊是西門口。
近來城主有意發展西大街，遂把許多鋪子遷移到這裡來，一時人潮湧洶，販夫走卒
不絕於途，兩旁皆是一排排的鋪子。而你右手邊是城內最大的旅館，有提供休息服
務。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SCITY"hotel1",
       	    "west" : SCITY"westgate",
       	   "north" : SCITY"wn1",
       	   "south" : SCITY"ws",
        ]) );
	reset();
}
