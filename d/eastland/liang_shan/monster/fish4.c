#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name("common carp", "鯉魚");
	add("id",({"fish","carp"}) );
	set_short("鯉魚");
	set_long(
		"這是一條褐黃色的鯉魚，有須兩對，是東方大陸人主要的淡水食用\n"
		"魚，相當的美味。\n"
	);
	set( "likefish",1);
	set( "unit", "條" );
	set( "alignment", 200 );
	set( "natural_weapon_class1", 7 );
	set( "natural_min_damage1", 4 );
	set_skill("swimming",100);
	set( "natural_max_damage1", 7 );
	set_c_limbs( ({ "頭部", "身體", "尾鰭" }) );
	set_c_verbs( ({ "%s張嘴，往%s咬去","%s尾鰭用力一甩，甩向%s" }) );
}

