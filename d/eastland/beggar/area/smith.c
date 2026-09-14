#include "/d/eastland/beggar/dony.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "『薪膽村』鐵匠鋪" );
	set_long(@C_LONG
這是『薪膽村』裡唯一的一家鐵匠鋪, 主人陸阿巧平時最喜歡為別人鑄劍了
。你仔細一看, 地上鋪滿了一層厚厚的細鐵屑, 那些鐵屑都是打鐵時濺落的火花
。鋪內有許多火爐和鐵砧。嚇!還有一個大鐵槌,還真不是普通人能拿得起來的呢
。
C_LONG
               	);
	set( "light", 1 );
	set( "exits", ([
		"east" : DBEGGAR"north2"
	]) );

	set( "objects", ([
		"fun" : DMONSTER"blackmaster"
	]) );
        set_reset(this_object(),21600);
}
void reset()
{
    set_reset(this_object(),21600);
    ::reset();
}

