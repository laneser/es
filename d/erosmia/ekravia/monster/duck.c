#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "duck", "鴨子" );
	add( "id", ({ "duck" }) );
	set_short( "鴨子" );
	set_long(
		"農家養的鴨子, 有著短短的脖子與黑色的羽毛。\n"
	);
	set( "unit", "只" );
	set_c_limbs( ({ "的腳", "頭部", "身體" }) );
	set_c_verbs( ({ "%s往%s一啄", "%s振翅往%s撞去" }) );
}
