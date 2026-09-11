#include "hole.h"

inherit ROOM;
void create()
{
	::create();
	set_short( "舊崗哨" );
	set_long(@LONG
這兒留下一些舊的軍用裝備和碉堡，目前已經廢棄不用了。原因是
從前駐守在此地的士兵常常會離奇的死亡，而且死狀奇慘，像是全身的
體液都被吸乾似的；由於苦苦無法查出原因，所以便決定將崗哨往後撤
，以免意外再度發生。
LONG
	);
	set( "exits",([
			"southwest" : HOLE"hole29"
			]) );
	reset();
#include <replace_room.h>
}
