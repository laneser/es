#include <mudlib.h>

inherit ROOM;
inherit DOORS;

void create()
{
   ::create();
   set_short( "小辦公室" );
   
   set_long(@CLONG
這是冒險者公會中一個不起眼的小辦公室，聽說很多冒險的資料都放在這個房
間，房間的角落有一張書桌( table)，書桌旁有兩張皮椅。旁邊放著幾盆觀葉
植物，為這個陰暗的角落增添一股生氣。
CLONG);
	set( "light",1 );
	set("c_item_desc",(["table":
"這張桌子上堆滿了許多的文件，但由於經過細心的整理，不但沒有雜亂的感覺， \n"
"反而另有一種壯觀的美感。桌上還放著一盞小巧的油燈，昏黃的燈光，使這間房間\n"
"多了一種古老但卻溫暖的感覺。油燈旁還有一個小香爐，正冒出縷縷的青煙。\n"	

	                   ,"censer":
"一個古色古香的小香爐，爐裡的香氣讓你想起古老的東方．\n"	

	]));
        set( "exits", ([
                "south" : "/d/adventurer/hall/adv_libra1",
                ]) );
                
         set("no_monster",1);
         
         set("objects",(["officer" : "/d/adventurer/hall/monsters/sophia"]));
         
         create_door("south","north",([
                     "keyword":({"woodendoor","door"}),
                     "status":"closed",
                     "c_desc":"一個小小的木門",
                     "c_name":"小木門",
                     "name":"small wooden door",
                     "desc":"a small wooden door",
                                     ]) );
         reset();                     
}
