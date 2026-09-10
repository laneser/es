// File: /d/noden/asterism/city_library.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("圖書館");
	set_long(
		@C_LONG_DESCRIPTION
這裡有一棟雄偉的大建築物,是艾斯特律恩(asterism)城的圖書館,大部份的書籍都
在地精魔族戰爭中被燒的殘缺不全了.但是仍有一些有價值的書籍被保存了下來.或許你
能找到隱藏其中的秘密.往北你將回到花園,而南邊是一座很高的塔.
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
	set( "light", 1 );
        set("c_item_desc",(["tower":"一座建築的很宏偉的高塔.\n"]));       
	set( "exits", ([ 
		"north":ASTR"city_garden",
		]) );
	reset();
}                         

void init()
{
   add_action("to_enter","enter");
   }
   
   int to_enter(string str)
   {
       if (!str)
        return notify_fail("進去哪兒啊?\n");
       if (str=="tower")      
          {
            write("你進入了塔中.\n");
               this_player()->move_player(ASTR"tower3-1",({
                     "%s進入了塔中.\n","%s從外面進來.\n",}),"");
             return 1;
           }
      
       if (str=="library")      
          {
            write("你進入了圖書館.\n");
               this_player()->move_player(ASTR"lib01",({
                     "%s進入了圖書館.\n","%s從外面進來.\n",}),"");
             return 1;      
           }
        return notify_fail("進去哪兒啊?\n");  
  
    }  
