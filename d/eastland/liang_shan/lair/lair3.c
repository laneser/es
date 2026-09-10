#include "../takeda.h"

inherit ROOM;

void create()
{
	::create();
        set_short("奇怪的洞穴");
	set_long( @LONG_DESCRIPTION
你一踏進這個地方，全身莫名的有覺得一種舒暢的感覺，與外面的邪惡氣息
完全不同，在你的面前有一塊巨大的石碑 (stele)，看來好像相當古老了，雖然
巖壁上或多或少的有些青苔，但石碑上面卻是光潔異常?
LONG_DESCRIPTION
	);

	set( "c_item_desc", ([ 
		"stele" : @LONG_TEXT
你走到石碑前，仔細的觀察它的表面，上面刻著許多奇怪的文字，看來
不是現存的任何一種。大約離地四尺的地方，有一個[□]型的凹陷奇怪記號
(mark)。
LONG_TEXT
, 
		"mark" : @LONG_TEXT
你仔細的檢查這個記號，看起來記號裡面的材質跟石碑表面有點不一樣?
但是光看是不能證明你的想法...		
LONG_TEXT
 ]) );
	set( "drag_appear",0 );
	set( "exits", ([ 
		"south" : TROOM"lair/lair2" ]) );
}


void init()
{
	add_action( "do_touch", "touch" );
}

int do_touch(string arg)
{
	object dragon;
	if( !arg || arg!= "mark" ) return 0;
        if ( present("dragon") ) return 0;
        if ( query("drag_appear") ) {
        tell_object(this_player(),
        "你摸了摸這個記號，一個悲傷的聲音在你的內心出現: 【孩子，一切都太遲了....】\n"); 
        return 1;
        }
        tell_object(this_player(),
        "你摸了摸這個記號，一個莊嚴的聲音在你的內心出現: 【孩子，我等你很久了....】\n"
        "你是來幫助我的嗎??\n");
        tell_room( this_object(), 
        "突然一陣劇烈的波動，一個巨大的生物突然出現在你面前....\n"
		 );
	set( "drag_appear",1 );
	dragon =new(TMONSTER"drag");
	dragon->move(TROOM"lair/lair3");
	return 1;
}
int clean_up() { return 0; }