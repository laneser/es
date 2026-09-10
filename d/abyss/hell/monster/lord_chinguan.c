// /d/abyss/hell/monster/lord_chinguan.c

#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name("Lord Chin-Guan", "秦廣王");
	add( "id", ({ "lord", "chin-guan", "chin", "guan" }) );
	set_short("Lord Chin-Guan", "秦廣王");
	set_long(
		"You see the Lord Chin-Guan.\n",
		"秦廣王是掌管森羅殿的冥王，他的職責是審判世人在陽間的所作所為是\n"
		"否該入地獄受罰，他的兩眼能看透人心，在秦廣王面前沒有任何人能說\n"
		"謊騙他。\n"
	);
	set( "gender", "male" );
	set( "no_attack", 1 );
}
