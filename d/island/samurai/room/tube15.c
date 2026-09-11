#include "mercury.h"

inherit ROOM;

void create()
{
   ::create();
   set_short( "忍者屋" );
   set_long(@ANGEL
你來到一個忍者屋，你現在終於知道是什麼人住在地下了，原來是武士城堡
的另一之部隊忍者們住在下面，因為是在地下，所牆壁上有好幾顆夜明珠擺著用
來照明，這裡的空間比外面通道大了很多，所以你感覺也較舒服，而奇怪的是這
裡的地板有很多大大小小的坑洞，好像有人在這練習一些奇怪的招式．
ANGEL
   
         );
         
	set( "light",1);
        set( "exits", ([
                "west":MR"tube14"
                ]) );
         reset();                     
}

