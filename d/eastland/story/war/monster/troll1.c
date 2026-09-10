#include "../../story.h"
inherit WMOB"warmob";

void create()
{
	::create();
	set_level(8);
	set_name( "troll soldier", "巨人族士兵" );
	add( "id", ({ "soldier","troll" }) );
	set_short( "巨人族士兵" );
	set_long(@LONG
一個兇猛的巨人族戰士，他正在蚩尤大軍裡奮勇殺敵。
LONG
	);
	set( "unit", "個" );
	set( "gender","male");
	set( "race","巨人");
	set( "alignment", -100 );
	set_natural_armor(35,1);
	set_natural_weapon(1,2,3);
	set( "wealth/silver", 50 );
	set( "killer", 1 );
        set( "pursuing", 1 );
        set( "speed",30);
        set( "moving", 1);
        set( "war_points", 15 );
	equip_armor(WARM"cloth1");
	wield_weapon(WWEA"blunt1");
	set_skill( "parry", 30 );
}
