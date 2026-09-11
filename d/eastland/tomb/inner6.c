#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("陵墓角落");
	set_long( 
@C_LONG_DESCRIPTION
這兒是陵墓的角落，冷冷的銀光自星空灑下。你看到許許多多的大櫃子放在牆邊，然而
它們似乎都被鎖上了，令你懊惱非常。從腳底下傳來陣陣的水聲以及絲絲的寒意，你想還是
趕快離開這兒的好。
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"south" : TOMB"/inner7",
		"east"  : TOMB"/inner5"  ]) );
	reset();	
}

void init()
{
	tell_object( this_player(), 
		"當你來到這兒時，一陣酷寒的水氣突然由你腳下冒起 !!\n"
		);
	this_player()->receive_special_damage("cold",100);
}
