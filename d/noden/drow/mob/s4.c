#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(12);
        set_name("snake","龜殼花" );
        set_short("snake","龜殼花" );
        set_long(
@C_LONG
這是一條美麗的龜殼花，你知道，這是某種名貴的蛇類，並且
含有劇毒，可是還是別碰它的好！
C_LONG
        );
        set( "unit", "條" );
        set( "alignment", -500 );
        set( "natural_weapon_class1", 12 );
        set( "natural_min_damage1", 10 );
        set( "natural_max_damage1", 15 );
        set( "tactic_func", "emit_poison" );
        set_c_limbs( ({ "頭部", "身體", "尾巴" }) );
        set_c_verbs( ({ "%s昂頭張嘴，往%s咬去" }) );
}

int emit_poison()
{
        object victim;

        if( random(15)>4 || !(victim= query_attacker()) ) return 0;
        tell_room( environment(this_object()),
                "龜殼花用它的尖牙狠狠的向你咬下，你覺得一陣刺痛 ....\n",
                this_object() );
        (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 
25, 9 );
        return 1;
}       
