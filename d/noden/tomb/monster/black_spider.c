#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "black spider", "黑蜘蛛" );
	add( "id", ({ "spider" }) );
   set_short( "黑蜘蛛" );
	set_long(
		"你看到一隻黑色的大蜘蛛，這種蜘蛛並不會結網，它們是專靠快速的行動\n"
		"與強有力的肢體捕食小動物，這隻蜘蛛的體型頗大，它看起來好像餓了。\n"
	);
   set("race","insect");
	set_perm_stat( "str", 2 );
	set( "alignment", -300 );
	set( "aggressive", 1 );

	set( "unit", "只" );
	set_c_verbs( ({ "%s張著兩隻大牙，往%s咬下", "%s用毛茸茸的前肢往%s一刺" }) );
	set_c_limbs( ({ "頭部", "身體", "腿部" }) );
}
