//#pragma save_binary

#include "../mage.h"
// Let players can use flare [2] , original limit is flare [1], modified in 1995/2/29

inherit "/d/mage/study1";
inherit ROOM;

void create()
{
	::create();
	set_short("A empty room", "黑魔法圖書室");
	set_long( @LONG_DESCRIPTION
NEED TRANSLATE HERE.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
這裡是專門收藏黑魔法卷軸的收藏室，據掌管這間收藏室的人估計，大約有
百分之九十以上目前已知的黑魔法咒語都能在這裡找到，在你的面前有一本厚重
的目錄(catalog)，你可以安靜地在這裡研讀(study)魔法書，或研究提升(raise
)魔法等級的知識，往東可以回到魔法圖書館的大廳。
C_LONG_DESCRIPTION
	);
    set( "no_monster", 1);
	set( "light", 1 );
	set( "exits", ([ 
		"east" : MAGE"library" ]) );
	set( "item_func", ([
		"catalog": "view_catalog" ]) );
	set_spells( ([
		"ether-bolt"  : ({ "black-magic", 20, 7, 10, 130 }),
		"lightning"   : ({ "black-magic", 50, 3, 10, 200 }),
		"flare"       : ({ "black-magic", 80, 2, 10, 500 }),
     "mirror-shield"  : ({ "black-magic", 40, 3, 15, 160 }),
     "energy-shield"  : ({ "black-magic", 40, 3, 15, 110 }),
	]) );
	reset();
}
