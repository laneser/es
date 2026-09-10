#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1, ob2;

	::create();
	set_level(2);
	set_name( "drunk", "醉漢" );
   set_short( "醉漢" );
	set_long(
		"You see a smelly drunk. He looks sad and down.\n",
		"一個渾身酒臭味的醉漢，看他失意潦倒的樣子，不知道是遭到什麼不幸\n"
		"還是自甘墮落。\n"
	);
	set_perm_stat( "str", 3 );
	set_skill( "dodge", 10 );
	set( "gender", "male" );
	set( "race", "human" );

	set( "alignment", -100 );
	
	ob1 = new( "/d/noden/farwind/items/coat" );
	ob1->move( this_object() );
	equip_armor( ob1 );
	
	ob2 = new( "/d/noden/farwind/items/bottle" );
	ob2->move( this_object() );
}
