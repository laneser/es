#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "shopkeeper", "商店主人" );
	add( "id", ({ "keeper", "shop keeper" }) );
   set_short( "商店主人" );
	set_long(
		"這位老闆是個年紀大約五、六十歲的諾頓人，由於他年輕的時候\n"
		"曾經到過許多地方遊歷，因此會說各種語言。\n"
	);
	set( "no_attack", 1 );
#include <replace_mob.h>
}
