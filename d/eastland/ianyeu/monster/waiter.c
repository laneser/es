#include "../mad.h"

inherit MONSTER;
inherit "/std/seller";
void create()
{
	::create();
	set_level(6);
   set_name( "waiter", "店小二" );
   set_short( "店小二" );
	set_long(
        "你看到一個面帶微笑, 不斷招呼客人坐下(sit down)的店小二。\n"
	);
	set( "race", "halfling" );
	set( "gender", "male" );
   set( "exp_reward", 111 );
// 懶得調狀態:P
   set( "wealth/copper", 10 );
	set_inventory( ({
           ({ IANOBJ"lamb", 10, 10 }),
           ({ IANOBJ"tea", 10, 10 }),
	}) );
}

void init()
{
	npc::init();
	seller::init();
}
