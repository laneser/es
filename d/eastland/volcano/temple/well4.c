#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
	::create();
	set_short( "井底" );
	set_long(
@LONG
你正處在這口井的井底。前面一片明亮，好像有一棟建築物，亮光正是從那裡傳來，
而且好像還有生物在那裡的樣子。
LONG
	);
	set( "exits", ([
             "south" : OTEMP"well3",
	     "north" : OTEMP"palace1",
	]) );
        reset();
}
