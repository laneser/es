#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name( "hole wolf", "穴狼" );
	add( "id", ({ "wolf" }) );
	set_short( "穴狼" );
	set_long(
		"這是一種居住於山洞之中的狼。 \n"
	);
	set_perm_stat( "str", 10 );
	set_skill( "dodge", 30 );

	set( "unit", "只" );
	set( "natural_weapon_class1", 10 );
	set( "natural_min_damage1", 6 );
	set( "natural_max_damage1", 9 );
	set( "killer", 1 );

	set_c_verbs( ({ "%s用前爪撲向%s", "%s張開滿口利齒的嘴，往%s咬去" }) );
	set_c_limbs( ({ "頭部", "身體", "尾巴", "腿部" }) );
#include <replace_mob.h>
}
