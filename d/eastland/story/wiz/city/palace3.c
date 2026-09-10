#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("皇宮大殿");
	set_long( @LONG
印入眼簾裡的是一脈連天接地閃閃發亮的萬頃金黃色波濤，原來這裡上天下地
左右牆壁都是用黃金鋪成，顯的貴氣十足！兩旁還有四根白玉雕成的巨大柱子，雖
然每一根刻劃的都是龍的形態，但只只造形獨特，表情不一，或潛或藏，或者盤旋
而起，進而張牙舞爪，個個令你歎為觀止目不暇已，巧奪天工疑為鬼神莫測之造！
另外兩旁各站著文官武將，討論著事誼。
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "north" : SCITY"palace4",
           "south" : SCITY"palace2"
        ]) );
        set( "objects", ([
           "scholar" : SWMOB"wiz_scholar1",
           "general" : SWMOB"wiz_general1"
        ]) );
	reset();
}
