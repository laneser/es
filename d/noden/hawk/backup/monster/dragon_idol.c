#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "dragon idol", "龍形傀儡" );
	add( "id", ({ "idol", "dragon" }) );
	set_short( "龍形傀儡" );
	set_long(
		"你看到一個巨大的龍形傀儡，它的四肢似乎被一些看不見的線牽動著。\n"
	);
	set( "unit", "只" );
	set( "race", "dragon" );
	set( "alignment", -1100 );
	set_natural_armor( 90, 40 );
	set_natural_weapon( 40, 24, 44 );
	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 26 );
	set( "hit_points", 1300 );
	set( "max_hp", 1300 );
	set( "tactic_func", "my_tactic" );
	set( "wealth/gold", 200 );
	set_c_limbs( ({ "頭部", "身體", "腿部", "尾巴" }) );
	set_c_verbs( ({ "%s張嘴往%s猛咬", "用巨爪抓向%s" }) );
}

int my_tactic()
{
	object *victim;

	if( random(20)<3 ) {
		tell_room( environment(this_object()), 
			"\n龍形傀儡發出一聲可怕的吼叫聲，從口中噴出許多黑色的氣體....。\n\n",
			this_object() );
		victim = query_attackers();
		victim->receive_special_damage( "magic", 50 );
		return 1;
	}
	return 0;
}
