#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "wraith staff", "矮靈權杖" );
	add( "id", ({ "staff" }) );
	set_short("矮靈權杖" );
	set_long(
		"這是一把矮靈族歷代相傳的權杖，它的末端鑄著一個貓眼石，\n"
                "貓眼石的瞳孔中似乎還閃著綠光。\n" );
	set( "unit", "把" );
	set( "type", "blunt" );
//	set( "hit_func", "weapon_hit" );
	set( "weight", 130 );
	set( "weapon_class", 30 );
	set( "min_damage", 15 );
	set( "max_damage", 30 );
	set( "value", ({ 1000, "silver" }) );
	set( "no_sale", 1 );
}

int weapon_hit( object victim, int damage )
{
	object owner;
	int intelligence, sp;

	owner = environment();
	intelligence = owner->query_stat("int");
	sp = owner->query("spell_points");
	if( random(intelligence)>15 && sp > 5 ) {
		tell_object( owner, 
               "\n你的權杖上貓眼石的瞳眼突然張開，從瞳眼中射出一道七彩光芒，"+victim->query("c_name")+
		"的靈魂似乎被吸了去\n你覺得一股力量從權杖上注入你的體內....\n\n");
		tell_object( victim, 
                owner->query("c_name") + "的權杖上貓眼石的瞳眼突然開，一道七彩光芒射向你，你的靈魂似乎被吸了去\n");
		tell_room( environment(owner),
                        owner->query("c_name") + "的權杖上的瞳眼突然張開，一道七彩光芒射向"
                        + victim->query("c_name") + "並且把他的靈魂吸了去！\n",
			({ victim, owner }) );
	victim->receive_special_damage( "evil", intelligence );
	owner->receive_healing( intelligence );
	owner->add( "spell_points", -5 );
	owner->add( "alignment", -100 );
	return intelligence * 2;
	}
}
