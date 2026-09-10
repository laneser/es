

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(2);
        set_name("bee", "野蜂");
        set_short("野蜂");
        set_long(
                "你看到一隻嗡嗡叫的野蜂，它正繞著花兒打轉，你最好不要惹它。\n"
        );
        set( "unit", "只" );
        set( "alignment", -100 );
	set( "tactic_func", "sting" );
        set_natural_weapon( 5, 2, 5 );
        set_natural_armor( 10, 4 );
        set( "c_death_msg", "%s無力地落到地上，死翹翹了 ....\n" );
        set_c_limbs( ({ "頭部", "身體", "翅膀" }) );
        set_c_verbs( ({ "%s發出嗡嗡的叫聲，往%s叮去" }) );
}

int sting()
{
        object victim;

        if( random(20)>4 || !(victim= query_attacker()) ) return 0;
        tell_object( victim, 
                "野蜂飛到你的臉上，你感到臉上一陣刺痛！\n");
        tell_room( environment(this_object()), 
                "野蜂飛到" + victim->query("c_name") + "的臉上，用尾針往下一螫！\n",
                this_object() );
        (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 5, 3 );
        return 1;
}
