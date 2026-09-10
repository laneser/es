#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name("golden carp", "鯽魚");
	add("id",({"fish","carp"}) );
	set_short("鯽魚");
	set_long(
		"這是一條淡黃色的鯽魚，漁夫們又叫它土鯽，大概是因為它是底生\n"
		"動物食性，其肉怎麼煮都帶土味之故。\n"
	);
	set( "unit", "條" );
	set( "likefish",1);
	set( "alignment", 300 );
	set( "natural_weapon_class1", 7 );
	set( "natural_min_damage1", 3 );
	set_skill("swimming",100);
	set( "natural_max_damage1", 7 );
	set_c_limbs( ({ "頭部", "身體", "尾鰭" }) );
	set_c_verbs( ({ "%s張嘴，往%s咬去","%s尾鰭用力一甩，甩向%s" }) );
}

