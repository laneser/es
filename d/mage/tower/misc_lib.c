//#pragma save_binary

#include "/d/mage/mage.h"

inherit "/d/mage/study1";
inherit ROOM;

void create()
{
	::create();
	set_short("A empty room", "雜項魔法圖書室");
	set_long( @LONG_DESCRIPTION
This is a simple room created by roommaker.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
這裡所收藏的魔法書多半是在整理銀色之塔遺蹟時，從一些破舊的石棺或箱子
中發現的，雖然它們多半殘缺不全，但是經過幾位著名魔法師的整理之後，也已經
初具規模，這裡平常較少有魔法師進來，所以到處積滿灰塵，你可以查閱前面書櫃
上的清單(list)，看看這裡有哪些法術的資料。往南通過一條長長的走道可以回到
圖書館大廳。
C_LONG_DESCRIPTION
	);
    set( "no_monster", 1);
	set( "light", 1 );
	set( "exits", ([ 
		"south" : MAGE"library" ]) );
	set( "item_func", ([
		"list" : "view_catalog" ]) );
	set_spells( ([
	   "wizard-eye"     : ({ "misc", 10, 3, 15, 150 }),
	   "magical-shield" : ({ "misc", 40, 2, 15, 200 }),
	   "detect-invis" : ({ "misc", 10, 6, 10, 250 }),
	   "detect-hide" : ({ "misc", 10, 6, 10, 250 }),
	   "magic-cube"     : ({ "misc", 20, 2, 20, 200 }),
	]) );
	reset();
}
