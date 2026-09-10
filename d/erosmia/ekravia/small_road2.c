#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("end of a small road","小路盡頭");
	set_long(@CLong
小路在這裡中止, 西邊的果園擋住了去路。一戶農家就在小路北邊,
你可以看到農家門口的空地上幾隻雞鴨悠閒地走來走去。
CLong
);
	set("exits", ([
		"east"		: HERE"small_road1",
		"north"		: HERE"farmer_house"
		]));
	set( "objects", ([
		"goose1"	: MOB"goose",
		"goose2"	: MOB"goose",
	]) );
	reset();
}
