#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name( "carter", "車伕" );
	set_short( "車伕" );
	set_long(
		"他們是一些腳伕兼車伕，專門幫鏢局趕車運鑣，現在他們正圍成一堆\n"+
		 "閒聊磕牙，一面等著生意上門。\n"
	);
	set( "unit", "名" );
	set_perm_stat( "str", 6 );
	set_perm_stat( "dex", 6 );
	set_skill( "dodge", 20 );
	set( "gender", "male" );
	set( "alignment", 100 );
	set_natural_armor( 10, 4 );
	set_natural_weapon( 1, 2, 5 );
	set( "wealth/gold", 2 );
#include <replace_mob.h>
}
