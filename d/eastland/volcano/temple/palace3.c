#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
        object ob;

	::create();
	set_short("龍宮大殿" );
	set_long(
@LONG
這是井龍宮的大殿，殿內藻井正中雕俯首金龍一條，八邊有團光水藻及福祿壽喜萬
五字行圖案圍繞，殿頂蓋黃琉璃瓦鑲綠剪邊，十六道五彩琉璃脊，寶瓶火焰珠攢尖頂，
美倫美奐，金碧輝煌。殿前兩根紅漆圓柱上雕有凌空欲飛的金龍，姿態生動。平常在寶
座上坐的是井龍王，兩旁站的是左右護衛，英姿挺拔，目光炯炯有神。這個大殿是龍王
和大臣們討論事情的地方，但在這小小的井中似乎可討論的事並不多。西邊可通到龍王
的寢宮，東邊可通到公主的寢宮。
LONG
	);
	set( "exits", ([
             "south" : OTEMP"palace2",
             "west" : OTEMP"palace4",
	     "east" : OTEMP"palace5",
	]) );
        set("objects", ([
            "lift_guard":OMONSTER"left_guard",
            "right_guard":OMONSTER"right_guard"
            ]) );
        set("light",1);
        reset();
}
