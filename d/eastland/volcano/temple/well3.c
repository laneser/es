#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
	::create();
	set_short("井底" );
	set_long(
@LONG
你正處在這口井的井底。水面上的任何動靜你已不得而知，你的四周全都被黑暗
和寂靜籠罩，但往前看去，你仍可以隱約查覺到有一些光線從那裡傳來。
LONG
	);
	set( "exits", ([
             "up":OTEMP"well2",
	     "north" : OTEMP"well4",
	]) );
        reset();
}
