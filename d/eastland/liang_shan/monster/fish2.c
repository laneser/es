#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name("top-minnow", "大肚魚");
	add("id",({"fish"}) );
	set_short("大肚魚");
	set_long(
		"頭部及體側都有大圓鱗，眼大口小頭尖，上下頷有細齒聚成齒帶，\n"
		"雜食性，環境適應性高。\n"
	);
	set("likefish",1);
	set( "unit", "條" );
	set( "alignment", -100 );
	set( "natural_weapon_class1", 3 );
	set( "natural_min_damage1", 1 );
	set( "natural_max_damage1", 3 );
	set_skill("swimming",100);
	set_c_limbs( ({ "頭部", "身體", "尾鰭" }) );
	set_c_verbs( ({ "%s張嘴，往%s咬去","%s尾鰭用力一甩，甩向%s" }) );
}

