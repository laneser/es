#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "little crab", "小螃蟹" );
	add( "id", ({ "crab" }) );
   set_short( "小螃蟹" );
	set_long(
		"這隻螃蟹雖然很小，但是這個沙灘也是足夠讓它橫行的地方。\n"
	);
	set( "natural_armor_class", 12 );
	set( "unit", "只" );
	set_c_verbs( ({ "%s用它的大螯往%s一夾" }) );
	set_c_limbs( ({ "身體", "硬殼" }) );
}
