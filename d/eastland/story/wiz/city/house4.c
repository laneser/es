#include "../../story.h"

inherit ROOM;
inherit DOORS;
void create()
{
        ::create();
	set_short("鐵扇公主的偏殿");
	set_long( @LONG
這裡是鐵扇公主的住所。地面整玉建成，玉質特佳，光明若鏡；四周彩壁畫梁
，內中翡翠傢俱，雲案玉幾，殿偏一個橢圓形寶塌，上面鳳凰錦被，繡巾羅帕，撲
鼻香氣，旁邊一面古色古香特製大銅鏡；全殿富貴十足，不可而語。
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "south" : SCITY"road1"
        ]) );
        set( "objects", ([
           "servant1" : SWMOB"f_servant1",
           "servant2" : SWMOB"f_servant1",
           "servant3" : SWMOB"f_servant1",
           "princess" : SWMOB"princess1",
        ]) );
	create_door( "south","north" ,([
	  "keyword" : ({ "golden door", "door" }),
	     "name" : "golden door",
	   "c_name" : "金門",
	   "c_desc" : "一個金澄澄的大門，上面各有兩個雀環。\n",
	   "status" : "closed"
	]) );
	reset();
}
