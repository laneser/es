#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name("grass carp", "草魚");
	add("id",({"fish","carp"}) );
	set_short("草魚");
	set_long(
		"這是一條褐黃色的草魚，無須，背暗腹白，魚唇極為粗糙，以水\n"
		"邊的禾草為主食。\n"
	);
	set( "unit", "條" );
	set( "likefish",1);
	set( "alignment", 200 );
	set( "natural_weapon_class1", 7 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 8 );
	set_skill("swimming",100);
	set_c_limbs( ({ "頭部", "身體", "尾鰭" }) );
	set_c_verbs( ({ "%s張嘴，往%s咬去","%s尾鰭用力一甩，甩向%s" }) );
}

