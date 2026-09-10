// /d/abyss/hell/monster/judge.c

#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name("judge", "判官");
	set_short("the assistant judge", "冥府判官");
	set_long(
		"This is a simple monster created by npc maker.\n",
		"這位判官正板著臉孔瞪著你，不知道他毫無血色的臉孔後面隱藏著\n"
		"什麼樣的想法。\n"
	);
	set( "gender", "male" );
	set( "no_attack", 1 );
}
