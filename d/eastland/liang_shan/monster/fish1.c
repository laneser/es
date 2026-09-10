#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name("sweetfish", "香魚");
	add("id",({"fish"}) );
	set_short("香魚");
	set_long(
		"這是一條美麗的魚，鱗片細小，口裂廣而深，下顎前端截平，緣有鋸\n"
		"齒，形狀似鏟以便於刮食岩石上的藻類為食。\n"
	);
	set("likefish",1);
	set( "unit", "條" );
	set( "alignment", 300 );
	set( "natural_weapon_class1", 6 );
	set( "natural_min_damage1", 3 );
	set_skill("swimming",100);
	set( "natural_max_damage1", 6 );
	set_c_limbs( ({ "頭部", "身體", "尾鰭" }) );
	set_c_verbs( ({ "%s張嘴，往%s咬去","%s尾鰭用力一甩，甩向%s" }) );
}

