#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name("cobra", "眼鏡蛇");
	set_short("眼鏡蛇");
	set_long(
		"這條眼鏡蛇是相當危險的，它正盤在那兒，口吐蛇信。\n"
	);
	set( "unit", "條" );
	set( "alignment", -500 );
        set( "killer", 1);
	set( "tactic_func", "emit_poison" );
	set_c_limbs( ({ "頭部", "身體", "尾巴" }) );
	set_c_verbs( ({ "%s昂頭張嘴，往%s咬去" }) );
}

int emit_poison()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
	tell_room( environment(this_object()),
		"眼鏡蛇從嘴巴噴出一股白色的毒液，剛好噴在你的面前 ....\n",
		this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 5, 8 );
	return 1;
}
