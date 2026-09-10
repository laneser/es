#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "Sword of Gonbu", "工布之劍" );
	add( "id", ({ "gonbu", "sword" }) );
	set_short( "工布之劍" );
	set_long(
		"這是一把有著異樣深藍色劍刃漾著寒光的古劍，劍柄上刻著四個篆字「工布神劍」。\n" );
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "hit_func", "weapon_hit" );
	set( "weight", 100 );
	set( "weapon_class", 44 );
	set( "min_damage", 28 );
	set( "max_damage", 46 );
	set( "value", ({ 3250, "silver" }) );
	set( "no_sale", 1 );
}

int weapon_hit( object victim, int damage )
{
	object owner;
	int intelligence, sp;

	owner = environment();
	intelligence = owner->query_stat("int");
	sp = owner->query("spell_points");
	if( random(intelligence)>=15 && sp > 20 ) {
		tell_object( owner, 
			"\n你的工布之劍突然發出一道青紫色的弧光，劍身變成明鏡一般的銀色！\n\n");
		tell_room( environment(owner), 
			"\n" + owner->query("c_name") + "的工布之劍突然發出一道青紫色的弧光，劍身變成明鏡一般的銀色！\n\n",
			owner );
		victim->receive_special_damage( "divine", intelligence * 3);
		owner->add( "spell_points", -20 );
		return intelligence * 3;
	}
}

int stop_wield( object player )
{
	if( (int)player->query("alignment") < 2000 ) {
		notify_fail("工布之劍似乎發出一股力量，使你無法駕馭它。\n");
		return 1;
	}
	if( (int)player->query_skill("longblade") < 100 ) {
		notify_fail( "工布之劍似乎發出一股力量，使你無法駕馭它。\n");
		return 1;
	}
	return 0;
}
