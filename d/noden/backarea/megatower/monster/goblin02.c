
#include "../megatower.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(3);
	set_name( "fat goblin", "小惡鬼" );
	add ("id", ({"goblin", }) );
	set_short( "fat goblin", "胖胖的小惡鬼" );
	set_long(
	"a fat goblin.\n",
    "一隻胖胖的小惡鬼, 他的手臂粗壯有力。\n");

    set( "alignment",-100);
    set( "gender", "male" );
    set( "unit", "個" );
	set_perm_stat( "kar", 4 );
	set_perm_stat( "str", 8 );
	set ("wealth", ([ "silver": 50 ]) );

	set_natural_armor(20,6);
    set_natural_weapon(8,7,12);
    set("aggressive",1);
}
