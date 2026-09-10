
#include "../layuter.h"

inherit ROOM;

void create()
{
	::create();
	set_short("龍穴");
	set_long( @C_LONG_DESCRIPTION
當你進入此洞穴時你發現此處是一個火山熔洞，四周都是奇怪的火紅色岩石，並且
有時有一些奇怪的岩石結晶，當其被火光映照之時，會反射出絢麗的光線，加上原有的
火紅構成一副優美的景色，令你幾乎忘了身在何處。
C_LONG_DESCRIPTION
	);
	set("objects",([
	    "woman_fighter":"/d/eastland/dragon/monster/woman_fighter"]));
	    
	set( "light", 0 );
	set( "exits", ([
	    "west" : Lcave"cave3",
		"leave" : "/d/eastland/7,18.east"
	]) );
	reset();
#include <replace_room.h>
}
