#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name("snake", "青竹絲");
	set_short("青竹絲");
	set_long(
		"一條翠綠的青竹絲。\n"
	);
	set( "unit", "條" );
	set( "alignment", -300 );
	set( "natural_weapon_class1", 8 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 5 );
	set( "tactic_func", "emit_poison" );
	set( "chat_chance",15);
	set( "chat_output", ({
		"青竹絲在你的腳邊遊走。\n" }) );
	set_c_limbs( ({ "頭部", "身體", "尾巴" }) );
	set_c_verbs( ({ "%s昂頭張嘴，往%s咬去" }) );
}

int emit_poison()
{
	object victim;

	if( random(15)>4 || !(victim= query_attacker()) ) return 0;
	tell_room( environment(this_object()), 
		"青竹絲張開嘴巴向你咬下，你覺得一陣刺痛 ....\n",
		this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 20, 3 );
	return 1;
}
