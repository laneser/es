#include <mudlib.h>
#include <stats.h>
#include <races.h>

inherit MONSTER;

void create()
{
	string *race, name;

	::create();
	set_level(2);
	race = get_dir( RACE_PREFIX );
	name = "" ;
	while(strsrch(name,".c")== -1)
	  { name = race[random(sizeof(race)-1)] ;}
	sscanf( name , "%s.c", name );
	set_name( name + " visitor", to_chinese(name) + "遊客" );
	add( "id", ({ name, "visitor" }) );
	set_short( to_chinese(name) + "遊客" );
	set_long(@C_LONG
這個從外國來的遊客似乎對若嵐城壯麗的建築十分喜愛，正瞪大眼睛
仔細欣賞城樓上的雕刻。
C_LONG
	);
	set( "gender", ({"male", "female" })[random(2)] );
	set( "race", name );
	set( "alignment", random(600)-300 );
	set_natural_armor( 10, 5 );
	set_natural_weapon( 4, 2, 4 );
	set_perm_stat( "str", 3 );
	set_perm_stat( "dex", 3 );
	set_perm_stat( "kar", 3 );
	set( "wealth/silver", 10 );
#include <replace_mob.h>
}
