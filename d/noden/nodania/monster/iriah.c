#include "../nodania.h"

inherit MONSTER;

void create()
{
	object ob1;

	::create();
	set_level(18);
	set_name("iriah", "依莉雅");
	add( "id", ({ "queen" }) );
	set_short("依莉雅皇后");
	set_long(@CLONG
依莉雅皇后和國王雖然只差十歲，但是她看起來只有三十歲不到。依莉雅
皇后和國王是因戀愛而結婚的，如果你在沒有其他人的地方問她有關耶拉
曼(yaramon)的事，也許她會願意透漏和國王認識的經過。
CLONG
	);
	set_perm_stat("int", 27);
	set_perm_stat("dex", 25);
	set_perm_stat("kar", 30);
	set_skill("dagger", 100);
	set_skill("dodge", 100);
	set( "alignment", 2500 );
	set( "max_hp", 600 );
	set( "hit_points", 600 );

	set( "gender", "female" );
	set( "race", "human" );
	set( "natural_defense_bonus", 80 );
	set( "natural_weapon_class1", 30 );
	set( "natural_min_damage1", 10 );
	set( "natural_max_damage1", 20 );
	set( "wealth/gold", 400 );
	set( "special_defense", ([ "all": 40 ]) );
	set( "tactic_func", "my_tactic" );

	ob1 = new( NODANIA"obj/knife" );
	ob1->move( this_object() );
	wield_weapon( ob1 );
}

int my_tactic()
{
	object *victim;
	int dam;

	if( !(victim= query_attackers()) || (random(20)>4) ) return 0;
	tell_room( environment(), 
        "\n依莉雅施展一種奇異的法術，使你覺得頭痛欲裂！\n\n");
	dam = 60 + random(20);
	victim->receive_special_damage( "divine", dam );
	return 1;
}
