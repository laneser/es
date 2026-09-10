#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name( "chicken", "公雞" );
	add( "id", ({ "chicken"}) );
        set_short( "公雞" );
	set_long(@C_LONG
一隻正在帶領一群小公雞的公雞。
C_LONG
	);
        set_perm_stat("str",3);
        set_perm_stat("dex",2);
	set( "natural_armor_class", 10 );
	set( "unit", "只" );
        set( "race","monster");
	set( "chicken",1);
	set_c_verbs( ({ "%s用它的咀向%s一啄" }) );
	set_c_limbs( ({ "鳳爪","雞冠","雞胸" }) );
        set( "tactic_func", "my_attack" );
}
int my_attack()
{
    object *env,victim;
    int i;
    
    env=all_inventory( environment(this_object()) );
    victim = query_attacker();
    if( !victim ) return 0;
                    
    for ( i=0;i<sizeof(env);i++ ) {
       if ( env[i]->query("chicken") ){
       env[i]->kill_ob( victim );
       victim->kill_ob( env[i] );
       }
    }
}