#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("迴廊");
	set_long( @LONG
迴廊往這個方向己經是到了盡頭。抬頭一望，前面一縷飛瀑凌空而降，宛如一
條白色匹練，自天際缺口處急瀉下來，於瀑底形成□天銀浪，各方推擠攢簇猶如萬
馬奔騰之勢，前鋒廣流十丈才漸趨平緩。廊道欄杆雕飾精細，西邊一面約百畝圓形
湖蕩，沿岸不是瑤草琪花，便是碧枝瓊樹；湖面若鏡，綠波鱗鱗，錦麟遊泳，暗香
時聞。湖面一座拱橋，雕鏤精細，巧奪天工，通體水晶建成，銀光燦爛，耀眼生輝
；湖中心一座四方形樓閣，高出水面約三尺，造型特朱，氣派莊嚴。

LONG
	);
        set("light",1);
        set("exits" , ([
             "south" : SPALACE"garden1",
            "bridge" : SPALACE"bridge1",
        ]) );
        set("pre_exit_func",([
            "bridge":"can_pass"]));
	reset();
}
int can_pass()
{
   if ( this_player()->query("palace_war") ) return 1;
   return 0;
}
