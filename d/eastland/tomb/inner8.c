#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("陵墓角落");
	set_long( 
@C_LONG_DESCRIPTION
這兒是陵墓的角落，冷冷的銀光自星空灑下。你看到許許多多的大箱子放在牆邊，然而
它們似乎都被鎖上了，令你頗覺懊惱。箱子旁有一面高大的銅鏡，一陣陣刺目的閃光自銅鏡
中發出，照的你頭暈目眩，你想還是趕快離開這兒的好。
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"north" : TOMB"/inner7",
		"east"  : TOMB"/inner1"  ]) );
	reset();	
}

void init()
{
	tell_object( this_player(), 
		"當你來到這兒時，銅鏡中突然發出一道強光穿過你的身體 !!\n"
		);
	this_player()->receive_special_damage("electric",100);
}
