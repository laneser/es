#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "flinty longsword", "燧石長劍" );
	add( "id", ({ "longsword", "sword" }) );
	set_short( "燧石長劍" );
	set_long(
		"這是一把用暗紅色燧石做成的的長劍，摸起來感覺溫溫的。\n" );
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "hit_func", "weapon_hit" );
	set( "weight", 110 );
	set( "weapon_class", 24 );
	set( "min_damage", 11 );
	set( "max_damage", 22 );
	set( "value", ({ 750, "silver" }) );
}

int weapon_hit( object victim, int damage )
{
	object owner, armor;
	int str;

	owner = environment();
	str = owner->query_stat("str");
	if( random(str)>12 && (armor= victim->query("armor/body")) ) {
		tell_object( owner, 
		        "\n你的隧石長劍擊中敵人的護甲，在上面留下一條焦黑的痕跡！\n\n"
			);
		tell_object( victim, 
			owner->query("c_name") + "的燧石長劍擊中你的的護甲，在上面留下一條焦黑的痕跡！\n"
                        );
		tell_room( environment(owner), 
			owner->query("c_name") + "的燧石長劍擊中敵人的護甲，在上面留下一條焦黑的痕跡！\n"
			,({ owner, victim }) );
		if( !armor->query("ac_damaged") ) 
			armor->set_short((string)armor->query("short") + " (受損)" );
		if( (int)armor->query("armor_class") > 1 )
			armor->add( "ac_damaged", 1 );
		victim->calc_armor_class();
	}
	return 0;
}
