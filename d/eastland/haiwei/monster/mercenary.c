#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(9);
	set_name( "mercenary", "鏢師" );
	set_short( "鏢師" );
	set_long(
		"這個鏢師剛從京城保了一趟鏢回來，現在正在這裡喝酒休息。\n"
	);
	set( "unit", "名" );
	set_perm_stat( "str", 13 );
	set_perm_stat( "dex", 12 );
	set_skill( "dodge", 50 );
	set( "special_defense", ([ "all": 10 ]) );
	set( "gender", "male" );
	set( "alignment", 100 );
	set_natural_armor( 40, 10 );
	set_natural_weapon( 20, 7, 15 );
	set( "natural_weapon_class2", 15 );
	set( "natural_min_damage2", 5 );
	set( "natural_max_damage2", 13 );
	set( "wealth/gold", 20 );
	set_c_verbs( ({ "%s踏步向前，一記直拳打向%s", "%s左腿往%s一踢",
		"%s使一招「沙僧拜佛」，右拳打向%s", "%s往前一縱，左足往%s踢去" }) );
#include <replace_mob.h>
}
