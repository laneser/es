#include <races.h>

inherit RACE_INSECT;

void create()
{
	::create();
	set_level(2);
	set_name( "bamboo beetle", "筍龜" );
	add("id", ({"beetle"}) );
	set_short( "筍龜" );
	set_long(
		"一隻小筍龜。\n"
	);
	set_perm_stat( "str", 5 );

	set( "unit", "只" );
	set( "alignment", 150 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage1", 4);
	set( "natural_max_damage1", 8);
	set( "chat_chance", 15 );
	set( "chat_output", ({
		"小筍龜飛呀飛的，令你想起小時候。\n" }) );
	set_c_verbs( ({ "%s用角往%s一頂", "%s張開大牙，往%s咬去" }) );
	set_c_limbs( ({ "頭部", "身體", "腳部", "甲殼" }) );
}
