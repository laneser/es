#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "wraith sword", "矮靈之劍" );
	add( "id", ({ "sword" }) );
	set_short( "矮靈之劍" );
	set_long(
                "這是一把用火山岩打造的寶劍，擁有相當大的破壞力。\n" );
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "hit_func", "weapon_hit" );
	set( "weight", 130 );
	set( "weapon_class", 25 );
	set( "min_damage", 15 );
	set( "max_damage", 20 );
	set( "value", ({ 1000, "silver" }) );
}

int weapon_hit( object victim, int damage )
{
	object owner;
        int    my_kar,vic_kar,sp;

	owner = environment();
        my_kar=(int)owner->query("str");
        vic_kar=(int)victim->query("str");
        sp=(int)owner->query("spell_points");
        if (sp < 3) return 0;
        if (vic_kar*2 > my_kar*3) return 0;
                owner->set("spell_points",sp-3);
		tell_object( owner, 
		"\n你的矮靈之劍放出一片紅色光芒，朧罩著"+victim->query("c_name")+"，"+victim->query("c_name")+"感覺到無比的炙熱。\n\n");
		tell_object( victim, 
		owner->query("c_name") + "的矮靈之劍放出一片紅色光芒，你被朧罩在炙熱的光芒裡\n");
		tell_room( environment(owner),
			owner->query("c_name") + "的矮靈之劍放出一片紅色光芒朧罩"
			+ victim->query("c_name")+" ！\n",
			({ victim, owner }) );
	victim->receive_special_damage( "fire", 10 );
	return 10;
}
