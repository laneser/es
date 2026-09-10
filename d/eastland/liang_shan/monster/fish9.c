#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name("pond loach", "泥鰍");
	add("id",({"fish","loach"}) );
	set_short("泥鰍");
	set_long(
		"這是一條細長的魚，有五對觸鬚，細小的褐斑密佈全身，魚體呈\n"
		"現筒狀且佈滿了黏液，這使得想要徒手抓到它變得相當困難。\n"
	);
	set( "likefish",1);
	set( "unit", "條" );
	set( "alignment", 100 );
	set( "natural_weapon_class1", 3 );
	set( "natural_min_damage1", 3 );
	set( "natural_max_damage1", 6 );
	set("wimpy",8);
	set_perm_stat("dex",16);
	set_skill("dodge",35);
	set_skill("swimming",100);
	set_c_limbs( ({ "頭部", "身體", "尾鰭" }) );
	set_c_verbs( ({ "%s張嘴，往%s咬去","%s尾鰭用力一甩，甩向%s" }) );
}

