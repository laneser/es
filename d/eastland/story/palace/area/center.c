#include "../../story.h"

inherit SPALACE"RR";
void create()
{
        ::create();
	set_short("天都大殿");
	set_long( @LONG
你正立足在天都大殿的中心。大殿地面原是用整片翠精碧玉建成的，玉質特佳
，光明若鏡，毛髮可鑑。環顧殿內，琉璃天瓦，上下兩相對照，發出七彩旋轉虹光
；殿中一金鼎，刻畫著山精海怪，張牙舞爪，各式各樣，不怪不出，無奇不有，與
整個格局顯得格格不入，詭異已極。另外在殿中還有塊白色的石頭(stone)。
LONG
	);
        set("light",1);
        set("exits" , ([
           "east" : SPALACE"e1",
           "west" : SPALACE"w1",
          "north" : SPALACE"n1",
          "south" : SPALACE"s1",
        ]) );
	set( "c_item_desc", ([
	  "stone" : @LONG
一顆有著純白色的石頭，石頭上寫著白色代表主要的意思，上面有被摸過(touch)的痕跡。

LONG
	]) );
	reset();
}
void init()
{
   add_action("do_touch","touch");
   ::init();
}
int do_touch(string arg)
{
    if ( !arg || arg !="stone" ) 
       return notify_fail("你要摸什麼東西？\n");
    write("\n\n你好奇地摸一摸這塊白色的石頭，只見一道白色的光線貫穿你的身子！\n\n\n\n\n");
    this_player()->move_player("/d/noden/14,9.noden",({
         "%s的身子被一道白色的光線貫穿！\n",
         "%s借著一道白色來到了這裡.\n"}),"");
    write("\n在白光之後，你被帶到了主大陸。\n");
    return 1;
}