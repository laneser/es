
#include "../island.h"
#include <mudlib.h>
#include <stats.h>

inherit ISLAND+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name("octpus", "大章魚");
	add("id",({"octpus"}));
	set_short("大章魚");
	set_long(@LONG
一隻超大型的章魚，它的八隻觸手正不斷的揮動著，你還是離它
遠點好了。
LONG
	);
	set( "unit", "只" );
	set( "alignment", -250 );
	set("max_hp",600);
	set("likefish",1);
	set("hit_points",600);
	set_perm_stat( "dex", 21 );
	set_perm_stat( "kar",16 );
	set_natural_weapon(45,12,24);
	set_skill( "unarmed" , 55 );
	set_natural_armor(52,15);
	set( "tactic_func", "emit_lick" );
	set_c_limbs( ({ "頭部", "觸手" }) );
	set_c_verbs( ({ "%s揮動它的觸手向%s鞭打而去" }) );
}

int emit_lick()
{
	object victim;

	if( random(19)>3 || !(victim= query_attacker()) ) return 0;
	else {
	  tell_room( environment(this_object()), 
		  "\n這章魚用它的觸手把"+victim->query("c_name")+"緊緊地捆住\n\n"
		  );
	  victim->receive_damage(1+random(4));
	  report(victim);	
	  return 1;
      }
}