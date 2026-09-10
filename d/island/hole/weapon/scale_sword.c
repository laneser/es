#include <../hole.h>

//inherit REPORT;
inherit WEAPON;

void create()
{
	set_name( "Fire Scale Sword","火麟劍" );
	add( "id",({ "sword" }) );
	set_short( "火麟劍" );
	set_long(@LONG
	這把劍上鑲了一片火麒麟的鱗片，是把罕見
	的好兵器。
LONG
		);
	set( "unit","把" );
	set( "type","shortblade" );
	set( "weapon_class",40 );
	set( "min_damage",20 );
	set( "max_damage",45 );
	set( "special_damage",25 );
	set( "weight",150 );
	set( "second",1 );
	set( "value",({ 3600,"silver" }) );
	set_c_verbs( ({ "%s在身旁劃了個圈，使出「日坐愁城」刺向%s",
			"%s迸出眩目光華，赤眼如針，使出「白陽破曉」攻向%s",
			"%s雀躍如狂，凌空一劃，□如烈日，使出「日麗中天」衝向%s",
			"%s綻出嚴密劍網，蔽天而至，使出「火麟蝕日」罩住%s" }) );
//	set( "hit_func","fire_damage" );
}

int fire_damage(object victim,int dam)
{
	object holder;
	int max;
	string msg1,msg2,him,me;

	dam=this_object()->query( "special_damage" );
	if ( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	if ( (int)holder->query_skill( "shortblade" )<88 ){
		tell_object( holder,"\n你的火麟劍忽然湧出一股黑色火焰將你全身燒得疼痛不堪！\n" );
		holder->receive_damage( dam+random(15) );
//		report( holder );
		victim->set( "last_attacker",holder );
		return dam;
	}
	else{
		if ( max = random(75)< 20 ){
			him=victim->query( "c_name" );
			me=holder->query( "c_name" );
			tell_object( holder,set_color("你的火麟劍忽然湧出一股黑色火焰將"+him+"燒個焦黑！\n","HIR") );
			tell_object( victim,set_color( me+"的火麟劍忽然湧出一股黑色火焰將你全身燒得疼痛不堪！\n","HIR") );
			tell_room( environment(holder),set_color(me+"的火麟劍忽然湧出一股黑色火焰將"+him+"燒個焦黑！\n","HIR"),({ holder,victim }) );
			victim->receive_damage( dam+max );
//			report( victim );
			victim->set( "last_attacker",holder );
			return dam;
		}
	return 0;
	}
}
	