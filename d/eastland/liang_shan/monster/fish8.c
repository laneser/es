#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name("snake-fish", "七星鱧");
	add("id",({"fish","snake"}) );
	set_short("七星鱧");
	set_long(
		"這是一條造型奇特的魚，學名是七星鱧，但一般人都叫它姑呆，\n"
		"看起來笨笨呆呆，好像一塊大木頭漂在水裡，事實上，它是一種兇猛\n"
		"的掠食性魚類。\n"
	);
	set( "likefish",1);
	set( "killer",1);
	set( "pursuing",1);
	set( "unit", "條" );
	set( "alignment", -200 );
	set_skill("swimming",100);
	set( "natural_weapon_class1", 10 );
	set( "natural_min_damage1", 7 );
	set( "natural_max_damage1", 14 );
	set_c_limbs( ({ "頭部", "身體", "尾鰭" }) );
	set_c_verbs( ({ "%s張嘴，往%s咬去","%s尾鰭用力一甩，甩向%s" }) );
}

