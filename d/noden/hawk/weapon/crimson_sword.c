#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "crimsom longsword", "長劍" );
	add( "id", ({ "longsword", "sword" }) );
	set_short( "鮮紅色長劍" );
	set_long(
		"這是一把有著奇異的鮮紅色劍刃的長劍。\n" );
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "hit_func", "weapon_hit" );
	set( "weight", 100 );
	set( "weapon_class", 18 );
	set( "min_damage", 9 );
	set( "max_damage", 18 );
	set( "value", ({ 450, "silver" }) );
}

int weapon_hit( object victim, int damage )
{
	object owner;
	int intelligence, sp;

	owner = environment();
	intelligence = owner->query_stat("int");
	sp = owner->query("spell_points");
	if( random(intelligence)>12 && sp > 5 ) {
		tell_object( owner, 
			"\n你的鮮紅色長劍突然爆出一股熊熊烈火，劍身被燒得通紅！\n\n"
		        ); 
		tell_room( environment(owner), 
			owner->query("c_name") + "的鮮紅色長劍突然爆出一股熊熊烈火，劍身被燒得通紅！\n",
			owner );
		victim->receive_special_damage( "fire", intelligence );
		owner->add( "spell_points", -5 );
		return intelligence;
	}
}
