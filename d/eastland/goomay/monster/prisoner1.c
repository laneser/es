#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name( "prisoner", "囚犯" );
	set_short( "囚犯" );
	set_long(
		"一個看起來很可憐的傢伙，他用茫然的眼神看著你。\n"
	);
	set( "unit", "名" );
	set( "gender", "male" );
	set_skill( "dodge", 40 );
	set( "natural_armor_class", 20 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 12 );
#include <replace_mob.h>
}
