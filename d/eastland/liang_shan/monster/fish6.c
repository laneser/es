#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name("Chinese catfish", "鯰魚");
	add("id",({"fish","catfish"}) );
	set_short("鯰魚");
	set_long(
		"鯰魚體扁而延長，頭部巨大，呈圓錐狀，以小水生動物為主食，\n"
		"若以清湯煮食，十分味美。\n"
	);
	set( "unit", "條" );
	set( "likefish",1);
	set( "alignment", 200 );
	set( "natural_weapon_class1", 7 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 9 );
	set_skill("swimming",100);
	set_c_limbs( ({ "頭部", "身體", "尾鰭" }) );
	set_c_verbs( ({ "%s張嘴，往%s咬去","%s尾鰭用力一甩，甩向%s" }) );
}

