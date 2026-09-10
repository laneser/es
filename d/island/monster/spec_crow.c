#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name("spectral crow", "鬼魅烏鴉");
	add( "id", ({ "crow" }) );
	set_short( "鬼魅烏鴉");
	set_long(@LONG
你看到一隻輪廓十分模糊的黑色烏鴉，一種不祥的預感告訴你這是種邪惡的化身。
LONG
	);
	set( "unit", "只" );
	set( "alignment", -300 );
	set_natural_armor( 10, 1 );
	set_natural_weapon( 7, 3, 8 );
	set_perm_stat( "int", 14 );
	set_perm_stat( "pie", 2 );
	set_perm_stat( "str", 5 );
	set( "aggressive", 1 );
	set( "tactic_func", "cry" );
	set_c_limbs( ({ "頭部", "身體", "翅膀" }) );
	set_c_verbs( ({ "%s用嘴向%s用力一啄", "%s用爪子往%s抓去" }) );
}

int cry()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
	tell_room( environment(this_object()), 
		"鬼魅烏鴉發出一陣淒厲的叫聲，嚇得你手腳發軟 ....\n",
		this_object() );
	WEAK->apply_effect( victim, 10 , 1 );
	return 1;
}
