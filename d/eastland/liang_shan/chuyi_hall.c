#include "takeda.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "聚義廳" );
	set_long(
	"這裡是梁山泊聞名天下的聚義廳，所有的頭目們在這裡歃血為盟，結\n"
	"成結拜兄弟，誓同生死，在東方大陸，這是友誼的最高表現。大廳的陳設\n"
	"非常簡單，幾張小蒲團，一個小香案，香案上一碗清水，幾束香，一把牛\n"
	"耳尖刀，這就是全部的擺設了。北邊有一個小門可以離開這裡。\n"
	);
	set( "light",1 );
        set( "exits", ([
                "out"  : TROOM"path5",    
                "north"  : TROOM"path6",
        ]) );
        reset();
}
int clean_up() { return 0; }