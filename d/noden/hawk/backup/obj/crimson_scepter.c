#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "crimson scepter", "權杖" );
	add( "id", ({ "mace","scepter" }) );
	set_short( "鮮紅色權杖" );
	set_long(
		"這是一把鮮紅色的權杖，它的末端鑄著一個有著三隻犄角惡魔的頭。\n" );
	set( "unit", "把" );
	set( "type", "blunt" );
	set( "hit_func", "weapon_hit" );
	set( "weight", 150 );
	set( "weapon_class", 28 );
	set( "min_damage", 16 );
	set( "max_damage", 27 );
	set( "value", ({ 950, "silver" }) );
	set( "no_sale", 1 );
}

int weapon_hit( object victim, int damage )
{
	object owner;
	int intelligence, sp;

	owner = environment();
	intelligence = owner->query_stat("int");
	sp = owner->query("spell_points");
	if( random(intelligence)>19 && sp > 5 ) {
		tell_object( owner, 
			"\n你的鮮紅色權杖上的惡魔頭突然睜開眼睛，從"+victim->query("c_name")+
			"身上咬下一塊血淋淋的肉！\n你覺得一股力量從權杖上注入你的體內....\n\n"
			);
		tell_object( victim, 
			owner->query("c_name") + "的鮮紅色權杖上的惡魔頭突然睜開眼睛，並且一口從你身上咬下一塊血淋\n"
			"淋的肉！\n"
                        );
       		tell_room( environment(owner),
			owner->query("c_name") + "的鮮紅色權杖上的惡魔頭突然睜開眼睛，並且從"
			+ victim->query("c_name") + "身上咬下一塊血淋淋的肉！\n"
			,({ victim, owner }) );
		victim->receive_special_damage( "evil", intelligence );
		owner->receive_healing( intelligence );
		owner->add( "spell_points", -5 );
		owner->add( "alignment", -100 );
		return intelligence * 2;
	}
}
