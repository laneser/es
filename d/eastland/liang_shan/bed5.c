#include <takeda.h>

inherit ROOM;

void create()
{
	object chin;
	::create();
	set_short( "軍官休息室" );
	set_long(
	"這裡是梁山泊典型的軍官休息室，隱藏在四棵巨大的松樹後面，\n"
	"由窗內看去，則是一片水洗般的青翠，觸目皆是綠意盎然的樹木，有\n"
	"如一個大盆景擺在你面前，空氣中有著高山的冷冽，但卻使人倍感舒\n"
	"暢。\n"
	);
	set( "light",1 );
        set( "exits", ([
                "south"  : TROOM"yard1",    
        ]) );
        chin = new(TMONSTER"chin");
        chin->move(this_object());

        reset();
}
int clean_up() { return 0; }
