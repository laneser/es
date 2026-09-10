#include <mudlib.h>

void create(object ob)
{
    if ( !ob ) return ;
	ob->set_level(1);
	ob->set_name( "green spider", "綠蜘蛛" );
	ob->add( "id", ({ "spider" }) );
   ob->set_short( "綠蜘蛛" );
	ob->set_long(
		"你看到一隻綠色的大蜘蛛，這種蜘蛛並不會結網，它們是專靠快速的行動\n"
		"與強有力的肢體捕食小動物，這隻蜘蛛的體型頗大，它看起來好像餓了。\n"
	);
   ob->set( "race", "insect" );
	ob->set_perm_stat( "dex", 2 );
	ob->set( "alignment", -300 );
	ob->set( "aggressive", 1 );

	ob->set( "unit", "只" );
	ob->set_c_verbs( ({ "%s張著兩隻大牙，往%s咬下", "%s用毛茸茸的前肢往%s一刺" }) );
	ob->set_c_limbs( ({ "頭部", "身體", "腿部" }) );
}
