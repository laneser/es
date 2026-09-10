#include "../saulin_temple.h"

inherit "/d/eastland/saulin_temple/monster/saulin.c";

void create()
{
	::create();
	set_level(8);
	set_name( "basic bonze", "少林武僧" );
	add( "id", ({ "bonze" }) );
	set_short( "少林武僧" );
	set_long(@C_LONG
你看到一個少林武僧，與其說他是來作戰的，倒不如說他是來搖旗
吶喊的來得恰當。
C_LONG
	);
	set( "unit", "名" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment",  300 );
	set( "wealth/silver", 50 );
	set( "aggressive", 1 );
	set( "pursuing", 1 );
	set( "killer",1 );
	set( "moving", 1 );
	set( "speed", 10 );
	set( "max_hp", 300 );
	set( "hit_points", 300 );
	set( "max_fp", 400 );
	set( "force_points", 400 );
	set_natural_weapon( 20, 10, 20 );
	set_natural_armor( 49, 20 );
	set_perm_stat( "str", 12 );
	set_perm_stat( "dex", 10 );
	set_skill( "shortblade", 50 );
	set_skill( "parry", 30 );
	set_skill( "defend", 40 );
	set( "chat_chance", 10 );
	set( "att_chat_output", ({
		 "少林武僧大叫: 師伯師兄們加油!!\n",
		 "少林武僧說道: 放下你的武器乖乖就縛吧!\n",
	}) );

	wield_weapon( SAULIN_OBJ"iron_blade" );
}
