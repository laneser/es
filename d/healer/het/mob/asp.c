#include <mudlib.h>
#include <conditions.h>
#include <stats.h>
#include "../wang.h"

inherit MONSTER;

void create()
{
	::create();
	seteuid(getuid());
	set_level(15);
	set_name("Snake","絲奎");
	add("id",({"snake"}) );
	set_short("毒蛇");

	set_long(@C_LONG
這條蛇叫絲奎, 體長三寸, 色彩斑斕, 兩眼間突出一枚銳刺, 
看起來有點詭異。不知道這條蛇為什麼會被關在這裡。
C_LONG
	);
	set_perm_stat("dex",30);
	set_perm_stat("con",30);
	set_natural_weapon(40,20,40);
	set("natural_armor_class",60);
	set("natural_defense_bonus",20);
	set( "special_defense",([
		"all"  : 40,
		"none" : 20,
		"cold" : -20,
		"poison" : 20,
		])
	);	

	set("alignment",-500);
	set("tactic_func","my_tactic");
	set_temp("rate",60);
     	set_c_verbs( ({ "%s昂頭張嘴，往%s咬去" }) );
}

int my_tactic()
{
	object vic;
	int sprate;
	sprate = (int)query_temp("rate");
	if ( random(sprate) < 15 || !(vic=query_attacker()) ) 
		return 0;
	tell_room( environment(this_object()),
		sprintf( "絲奎從嘴巴噴出一股氣體, 剛好噴在%s面前...\n",
			vic->query("c_cap_name")),
	this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( vic, 20, 6 );
	if (random(sprate) > 30 )
		return 0;
	else
		return 1;
}

