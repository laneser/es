#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "大演武場" );
	set_long(
	"這裡是山寨內著名的大演武場，平時豹子頭林沖都在此操練部下．訓\n"
	"練格鬥或陣法．場邊放著各式的兵刃，發出森森的寒光．如果你想加入山\n"
	"寨，最快的方法就是在此顯顯身手．這裡豎著幾面旗幟，吸引你的目光\n"
	);
	set( "light",1 );
        set_outside( "eastland" );
        set( "c_item_desc",(["flag":
        "這些旗幟高聳入雲，直插天際，如果輕功不好，是上不去的\n"
        ]));
        set( "exits", ([
                "east" : TROOM"plaza2",
                "south"  : TROOM"path2",    
                "north"  : TROOM"plaza5",
                "west" : TROOM"plaza1"
        ]) );
        set( "objects",([
                "bandit":TMONSTER"small_bandit",
                "zhu":TMONSTER"zhu"
        ]) );        
        reset();
}
void init()
{
add_action("do_climb","climb");
}
int do_climb(string arg)
{
if ( !arg || arg!="flag")
return notify_fail(
"爬什麼?\n");
write (
"還沒完成, 請過兩天來爬\n");
}
int clean_up() { return 0; }