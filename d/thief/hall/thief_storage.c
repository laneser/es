#include <mudlib.h>
inherit ROOM;

init()
{
	add_action("do_drop","drop");
}
do_drop(string str)
{
	int tmp1,tmp2;
	string stmp1,stmp2;
	if ( ! wizardp(this_player()) ) return 0; 	// 測試時用
#if 0
	if ( !str ) return 0;
	if( sscanf(str, "%d %s %s", tmp1, stmp1, stmp2) == 3 ||
        	sscanf(str, "%d %s", tmp1, stmp1) == 2) return 0;
	if ( str == "all" )
		return notify_fail("請一樣一樣放.\n");
#endif
	
}

void create()
{
	::create();
	set_short( "小偷公會儲藏室");
	set_long(	@C_LONG_DESCRIPTION
這裡是小偷公會的儲藏室。幾年前一些有錢的小偷捐了些錢蓋了這座儲藏室,
高等級的小偷把一些多餘的裝備留在這裡, 提供需要的人取用。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"east" : "/d/thief/hall/thief_shop" ]) );
}

int clean_up() { return 0; }
