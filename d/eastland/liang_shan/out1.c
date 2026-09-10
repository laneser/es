#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "小路" );
	set_long(
"這是一條地圖上找不到的小路，兩旁長滿了長長的蘆葦，隨風搖曳。\n"	  
"傳說這兒常有翦徑強人出沒，他們會不會就躲在蘆叢內呢?\n"
	);
	set_outside("eastland",1);
        set( "exits", ([
                "north" : TROOM"gate1",
                "south" : TROOM"out2"
        ]) );
        reset();
}
void init()
{
object bandit;
if ( random(100)>1 || present("thief") ) return 0;
write(
"突然一聲大喊，一個山賊笨手笨腳的從蘆叢中鑽出，高舉著明晃晃的\n"
"鋼刀，對你露出曖昧的微笑。\n");
bandit =new("/d/eastland/monster/mt_bandit");
bandit->move(TROOM"out1");
}
int clean_up() { return 0; }