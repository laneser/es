#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "mercenary", "鏢師" );
	set_short("鏢師" );
	set_long(
		"這些鏢師閒來無事，圍著一堆正在閒磕牙，一面等著生意上門。\n"
	);
	set( "unit", "名" );
	set_perm_stat( "str", 13 );
	set_perm_stat( "dex", 12 );
	set_skill( "dodge", 70 );
	set( "special_defense", ([ "all": 10 ]) );
	set( "gender", "male" );
	set( "alignment", 100 );
	set_natural_armor( 40, 16 );
	set_natural_weapon( 13, 9, 16 );
	set( "wealth/gold", 10 );
#include <replace_mob.h>
}
