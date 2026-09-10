#include "../island.h"
#include <mudlib.h>
#include <stats.h>

inherit ISLAND+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name("octpus", "章魚");
	add("id",({"octpus"}));
	set_short("章魚");
	set_long(@LONG
一隻大型的章魚，正用著它的觸手尋找食物，請不要惹它。
LONG
	);
	set( "unit", "只" );
	set( "alignment", -250 );
	set("max_hp",400);
	set("likefish",1);
	set("hit_points",400);
	set_natural_weapon(30,9,15);
	set_natural_armor(40,10);
	set( "unarmed" , 40 );
	set( "tactic_func", "emit_lick" );
	set_c_limbs( ({ "頭部", "觸手" }) );
	set_c_verbs( ({ "%s揮動它的觸手向%s鞭打而去" }) );
}

int emit_lick()
{
	object victim;

	if( random(25)>3 || !(victim= query_attacker()) ) return 0;
	else {
	  tell_room( environment(this_object()), 
		  "\n這章魚用它的觸手把"+victim->query("c_name")+"緊緊地捆住\n\n"
		  );
	  victim->receive_damage(1+random(3));
	  report( victim );	
	  return 1;
      }
}
