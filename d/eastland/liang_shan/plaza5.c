#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "大演武場" );
	set_long(
	"這裡是山寨內著名的大演武場，平時豹子頭林沖都在此操練部下．訓\n"
	"練格鬥或陣法．場邊放著各式的兵刃，發出森森的寒光．如果你想加入山\n"
	"寨，最快的方法就是在此顯顯身手．北邊的建築即為點將臺，林沖現在應\n"
	"該在裡面．\n"
	);
	set_outside("eastland");
	set( "light",1 );
        set( "exits", ([
                "east" : TROOM"plaza3",    
                "north"  : TROOM"plate",
                "west" : TROOM"plaza4",
                "south" : TROOM"flag"
        ]) );
        reset();
}
int clean_up() { return 0; }