#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("陵墓角落");
	set_long( 
@C_LONG_DESCRIPTION
這兒是陵墓的角落，冷冷的銀光自星空灑下。你看到許許多多的大箱子放在牆邊，然而
它們似乎都被鎖上了，令你頗覺懊惱。從腳底下傳來陣陣的熱氣，你想還是趕快離開這兒的
好。
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"north" : TOMB"/inner3",
		"west"  : TOMB"/inner1"  ]) );
	reset();	
}

void init()
{
	tell_object( this_player(), 
		"當你來到這兒時，一片火焰突然由你腳下冒起 !!\n"
		);
	this_player()->receive_special_damage("fire",100);
}
