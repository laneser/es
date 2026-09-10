#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name( "black crow", "烏鴉" );
	add( "id", ({ "crow" }) );
	set_short( "烏鴉" );
	set_long(@LONG
這隻烏鴉非常吵，讓你有一股把它一腳踹死的衝動。
LONG
	);
	set_perm_stat( "dex", 3 );

	set( "unit", "只" );
	set( "natural_weapon_class1", 3 );
	set( "natural_min_damage1", 3 );
	set( "natural_max_damage1", 5 );
	set_c_verbs( ({ "%s往下俯衝，用嘴巴啄%s", "%s用爪子往%s抓下" }) );
	set_c_limbs( ({ "頭部", "身體", "翅膀" }) );
}
