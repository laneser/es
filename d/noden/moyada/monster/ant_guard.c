#include "../moyada.h"
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name("ant guard", "守衛蟻");
	add( "id", ({ "ant" }) );
	set_short("守衛蟻");
	set_long(
		"被選為守衛蟻穴的騎士蟻，其戰力更無法估計。\n"
	);
	set( "max_hp",300);
	set( "hit_points",300);
	set( "unit", "只" );
   set( "race", "insect" );
	set( "alignment", 500 );
	set_natural_weapon( 25, 15, 25 );
	set_natural_armor( 55, 25 );
	set_perm_stat("str",25);
	set_perm_stat("dex",24);
	set_perm_stat("con",26);
	set( "weight", 100);
	set( "c_death_msg", "%s尖叫一聲，抖了幾下不動了 ....\n" );
	set_c_limbs( ({ "頭部", "身體", "腳" }) );
	set_c_verbs( ({ "%s狠狠的往%s咬下去" }) );
	set( "tactic_func", "call_help");
	set( "alt_corpse", MOYADA"obj/ant_corpse1" );
}

int is_a_ant(object obj)
{
   if( (string)obj->query("race")=="insect" ) return 1;
   return 0;
}

int call_help()
{
    object victim, env, obj, *ants;
    int i;
    victim = query_attacker();
    env = environment( this_object() );
    
    if( !victim ) return 0;
    ants = filter_array( all_inventory( env ), "is_a_ant", this_object() );
    i = sizeof( ants );
    while( i-- )
      if( !ants[i]->query_attackers() )
        ants[i]->kill_ob(victim);
    return 0;
}
