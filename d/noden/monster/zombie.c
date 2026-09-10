#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "zombie", "殭屍" );
   set_short( "殭屍" );
	set_long(
		"一具又醜又兇惡的殭屍。\n"
	);
   set( "race", "undead" );
	set( "gender", "male" );
	set( "alignment", -400 );
	set( "aggressive", 1 );
	set( "tactic_func", "my_tactic" );
	set_c_verbs( ({"%s用他的僵直的爪子抓向%s", "%s張開嘴往%s咬去",
		"%s五指張開，猛然往%s插下" }) );
}

int my_tactic()
{
	object victim;
	int dam;

	if( !(victim= query_attacker()) || (random(20)>2) ) return 0;
    tell_room( environment(),
            "殭屍口中發出一些怪聲，使你覺得一陣暈眩....好像力量被吸走了。\n",
		this_object() );
	dam = 15 + random(10);
	victim->receive_special_damage( "evil", dam );
	receive_healing( dam );
	return 1;
}

