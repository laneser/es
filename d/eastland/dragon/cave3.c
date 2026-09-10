
#include "../layuter.h"

inherit ROOM;

void create()
{
	::create();
	set_short("龍穴");
	set_long( @C_LONG_DESCRIPTION
當你進入此洞穴時你發現此處是一個火山熔洞，四周都是奇怪的火紅色岩石，並且
有時有一些奇怪的岩石結晶，當其被火光映照之時，會反射出絢麗的光線，加上原有的
火紅構成一副優美的景色，令你幾乎忘了身在何處。山洞到了此處居然有分叉，頗令人
不知何去何從。
C_LONG_DESCRIPTION
	);
	set( "light", 0 );
	set( "exits", ([
	    "east" : Lcave"cave2",
		"northwest" : Lcave"cave4",
		"southwest" : Lcave"cave5"
	]) );
	reset();
#include <replace_room.h>
}
