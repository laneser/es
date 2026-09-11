#include "takeda.h"

inherit ROOM;

void create()
{
	::create();
	set_short("湖濱");
	set_long( @C_LONG_DESCRIPTION
你來到一片平坦的沙地，柔細的黃沙使得你的身後，留下一行深深的足印，偶爾
清風吹起，湖面泛起陣陣漣漪，不禁令人有出世之想，沙地旁的草叢長滿了不知名的
野花。
C_LONG_DESCRIPTION
	);

	set_outside("eastland");
	set( "exits", ([ 
		"west" : TLAND"out3",
		"north" : TROOM"beach9" ]) );
	reset();
}
