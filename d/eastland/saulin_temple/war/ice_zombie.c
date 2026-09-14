
#include "saulin_war.h"
#include <stats.h>
#include <conditions.h>

inherit War;

void create()
{
        ::create();
        set_level(9);
        set_name("ice zombie", "鬼□");
	add( "id", ({ "zombie", }) );
        set_short("鬼□");
        set_long(
                "它是陰玄冰用邪術合成的殭屍，一身屍毒令人聞之色變。\n"
        );
        set( "unit", "具" );
	set( "alignment", -600 );
        set( "pursuing", 1 );
        set( "killer", 1 );
        set( "monk_value", 15 );
        set( "natural_weapon_class1", 8 );
        set( "natural_min_damage1", 3 );
        set( "natural_max_damage1", 8 );
        set( "tactic_func", "emit_poison" );
        set( "wealth/gold", 25 );
        wield_weapon(Obj"skeleton_claw");
}

int emit_poison()
{
        object victim;

        if( random(20)>4 || !(victim= query_attacker()) ) return 0;
        if( random(10)<5 ) {
                tell_room( environment(this_object()), 
                        "鬼□從嘴巴噴出一股血紅色的臭氣，你感到一陣暈眩 ....\n",
                        this_object() );
                (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 15,6 );

	} else {
                tell_room( environment(this_object()), 
                        "鬼□發出一串尖銳的嘶吼聲，你的腦子一陣刺痛！\n",
                        this_object() );
                (CONDITION_PREFIX + "confused")->apply_effect( victim, 15, 5 );
	}
        return 1;
}
