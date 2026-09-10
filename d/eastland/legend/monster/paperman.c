#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "paper man", "紙人" );
	add( "id",({"man"}) );
	set_short( "紙人" );
	set_long(@C_LONG
一個由符咒變出來的紙人，它正凶猛地攻擊敵人。
C_LONG	
        );
        set( "unit", "個" );
	set( "killer", 1);
	set_perm_stat( "str", 22 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "kar", 20 );
        set("weight",650);
	set_skill( "dodge", 30 );
	set( "special_defense", ([ "all": 20 ]) );
        set( "alignment", -200 );
	set_natural_armor( 15, 5 );
	set_natural_weapon( 40, 18, 20 );
        set_natural_weapon( 40, 15, 25 );
        set("paperman",1);
}
void die()
{
   set("alt_corpse","NONE");
   ::die(1);
}