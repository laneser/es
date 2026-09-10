
#include "../megatower.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(1);
	set_name( "little goblin", "小惡鬼" );
	add ("id", ({"goblin", }) );
	set_short( "little goblin", "小惡鬼" );
	set_long(
	"a little goblin.\n",
    "一隻小小的小惡鬼。\n");

    set( "alignment",-100);
    set( "gender", "male" );
    set( "unit", "個" );
	set_perm_stat( "kar", 2 );
	set ("wealth", ([ "silver": 10 ]) );

	set_natural_armor(4,1);
    set("aggressive",1);
}
