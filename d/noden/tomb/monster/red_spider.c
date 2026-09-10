#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "red spider", "紅蜘蛛" );
	add( "id", ({ "spider" }) );
   set_short( "紅蜘蛛" );
	set_long(
		"你看到一隻體型碩大的紅蜘蛛，這種蜘蛛並不會結網，它們是專靠快速的行動\n"
		"與強有力的肢體捕食小動物，這隻蜘蛛的體型頗大，它看起來好像餓了。\n"
	);
   set("race","insect");
	set_perm_stat( "dex", 7 );
	set( "natural_weapon_class1", 12 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 9 );
	set( "alignment", -600 );
	set( "aggressive", 1 );
	set( "pursuing", 1 );
	set( "tactic_func", "my_tactic" );

	set( "unit", "只" );
	set_c_verbs( ({ "%s張著兩隻大牙，往%s咬下", "%s用毛茸茸的前肢往%s一刺",
		"%s用身上尖銳的硬毛往%s螫去" }) );
	set_c_limbs( ({ "頭部", "身體", "腿部" }) );
}

int my_tactic()
{
	object *victim;
	int i;

	if( random(20)<15 || !(victim = query_attackers()) ) return 0;
    tell_room( environment(),
            "紅蜘蛛口中噴出一股紅色的氣體，使你覺得手腳發軟，昏昏欲睡！\n" );
	for( i=0; i<sizeof(victim); i++ )
		victim[i]->receive_special_damage( "poison", 16 );
	return 1;
}
