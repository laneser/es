#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "scholar dagger", "學者之匕" );
	add( "id", ({ "dagger" }) );
	set_short( "學者之匕" );
	set_long(
                "這是一把學者之匕，上面刻了許多篆文。\n" );
	set( "unit", "把" );
	set( "type", "dagger" );
//	set( "hit_func", "weapon_hit" );
	set( "weight", 100 );
	set( "weapon_class", 28 );
	set( "min_damage", 18 );
	set( "max_damage", 25 );
	set( "value", ({ 1500, "silver" }) );
}
/*
int weapon_hit( object victim, int damage )
{
	object owner;

	owner = environment();
	if( random(50)<20 ) {
		tell_object( owner, 
                "\n你的學者之匕飄出一段古代的咒語攻擊"+victim->query("c_name")+"\n\n");
		tell_object( victim, 
                owner->query("c_name") + "的學者之匕飄出一段古代的咒語攻擊你。\n");
		tell_room( environment(owner),
                        owner->query("c_name") + "的學者之匕飄出一段古代的咒語攻擊"+victim->query("c_name")+" !\n", ({victim, owner}) );
	victim->receive_special_damage( "energy", 20 );
	return 20;
	}
}
*/