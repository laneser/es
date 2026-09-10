#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "carter", "車伕" );
	set_short( "車伕" );
	set_long("這名車伕看起來像是趕了很長的路，他正坐在客棧前的臺階上休息。\n");
	set( "unit", "名" );
	set( "gender", "male" );
	set( "race", "human" );
	set_perm_stat( "str", 3 );
	set_natural_weapon( 3, 3, 3 );
	set( "alignment", 200 );
	set( "wealth/gold", 1 );
#include <replace_mob.h>
}
