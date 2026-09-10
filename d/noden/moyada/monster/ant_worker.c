// /d/noden/monster/snake.c

#include "../moyada.h"
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name("ant worker", "工蟻");
	add( "id", ({ "ant" }) );
	set_short("工蟻");
	set_long(
		"一隻辛勤工作的工蟻。\n"
	);
	set( "max_hp",40);
	set( "hit_points",40);
	set( "unit", "只" );
   set( "race", "insect" );
	set( "alignment", 50 );
	set( "weight", 100);
	set( "natural_weapon_class1", 7 );
	set( "c_death_msg", "%s尖叫一聲，抖了幾下不動了 ....\n" );
	set_c_limbs( ({ "頭部", "身體", "腳" }) );
	set_c_verbs( ({ "%s狠狠的往%s咬下去" }) );
	set( "tactic_func", "call_help");
    set( "exp_reward", 40 );
    set( "alt_corpse", "/d/noden/moyada/obj/ant_corpse2" );
}

int is_a_ant(object obj)
{
   if( (string)obj->query("race")=="insect" ) return 1;
   return 0;
}

int call_help()
{
    object victim, obj, env, *ants;
    int i, number, left;
    victim = query_attacker();
    env = environment( this_object() );
    if( !victim ) return 0;
    
    ants = filter_array( all_inventory( env ), "is_a_ant", this_object() );
    number = sizeof(ants);
    i = number;
    while( i-- )
      if( !ants[i]->query_attackers() )
        ants[i]->kill_ob(victim);
    left = env->query("ant_left");
    if( random(20)>4 || number > 6 || left < 1 ) return 0;
    if( random(10) > 7 ) {
      tell_room( env, 
        "工蟻叫出工蟻來幫忙抵抗入侵者。\n" , this_object()
      );
      left--;
      env->set("ant_left", left);
      obj = new( MOYADA"monster/ant_worker");
      obj->move( environment(this_object()) );
      obj->kill_ob(victim);
    } else if( random(10)>5 ) {
      tell_room( env, 
        "工蟻叫出兵蟻出來幫忙抵抗入侵者。\n" , this_object()
      );
      left--;
      env->set("ant_left", left);
      obj = new( MOYADA"monster/ant_fighter");
      obj->move( environment(this_object()) );
      obj->kill_ob(victim);
    } else {
      tell_room( env, 
        "工蟻叫出殺人蟻出來幫忙抵抗入侵者。\n" , this_object()
      );
      left--;
      env->set("ant_left", left);
      obj = new( MOYADA"monster/ant_killer");
      obj->move( environment(this_object()) );
      obj->kill_ob(victim);
    }
    return 1;
}
