#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Lay Chou-Tan", "雷九天" );
	add ("id", ({ "master", "lay", }) );
	set_short( "屠龍劍派二代掌門 雷九天");
	set_long( @LONG
雷九天是屠龍劍派祖師屠龍道人的關門弟子，跟他的五位師兄一樣，
他是一名孤兒，屠龍道人收養了他。不過他跟隨屠龍道人學藝的時間很短
，大部分的武功心法都是他的大師兄風自在所傳，所以他的武功和五位師
兄略有不同而能自成一格。在他的五位師兄奉師命出門行道之後，他奉命
執掌屠龍派，而成為屠龍劍派的二代掌門。
LONG
	);
	set_perm_stat("str", 30 );
	set_perm_stat("con", 25 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "dodge", 100 );
	set( "alignment", 1500 );

	set( "race", "human" );
	set( "gender", "male" );

	set( "hit_points", 2000 );
	set( "max_hp", 2000 );
	set( "aim_difficulty",
	    ([ "critical":70,"vascular":80,"weakest":70,"ganglion":60 ]) );
	set_natural_weapon( 50, 15, 30 );
	set_natural_armor( 90, 60 );
	set ("special_defense", ([
		"all": 40 , "none" : 50]) );

	wield_weapon( "/d/swordman/guild/weapons/anti-god" );
	equip_armor( "/d/swordman/guild/armors/lay_plate" );
	equip_armor( "/d/swordman/guild/armorsblue/lay_pants" );
	equip_armor( "/d/swordman/guild/armors/lay_gloves" );
	equip_armor( "/d/swordman/guild/armors/lay_boots" );
	equip_armor( "/d/swordman/guild/armors/lay_amulet" );
}
