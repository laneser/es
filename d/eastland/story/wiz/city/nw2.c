#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("北大街");
	set_long( @LONG
你走正走在「巫咸城」內北大街上，大街往東、西方向延伸。由於北大街地處
偏僻，往來無塵囂，街旁樹木稀稀落落於一排排的房子間，空氣清幽，顯的格外清
新脫落，街道內相當安靜，是為居住之地。往東走可通往北門口，南邊有一間小房
子，裡面朗誦聲音不斷，原來是間私塾。
LONG
	);
        set("light",1);
	set( "exits", ([ 
            "east" : SCITY"nn",
            "west" : SCITY"wn2",
           "south" : SCITY"house2",
        ]) );
	reset();
}
