#include <mudlib.h>

inherit MONSTER;

void create()
{
	object ob1;

	::create();
	set_level(16);
	set_name( "tamumu monk", "塔姆姆僧侶" );
	add( "id", ({ "monk", "tamumu" }) );
	set_short( "塔姆姆僧侶" );
	set_long("這個塔姆姆僧侶對你視而不見，好像你根本不存在一樣。\n"
	);
	set( "unit", "名" );
   set( "race", "hawkman" );
	set( "gender", "male" );
	set( "alignment", -700 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "int", 17 );
	set_perm_stat( "pie", 18 );
	set_skill( "dodge", 90 );
	set_skill( "tactic", 90 );

	set( "tactic", "assault" );
	set( "wealth/gold", 25 );
	set( "pursuing", 1 );
	set( "natural_armor_class", 70 );
	set( "natural_defense_bonus", 20 );
	set( "natural_weapon_class1", 30 );
	set( "natural_weapon_class2", 25 );
	set( "natural_min_damage1", 11 );
	set( "natural_max_damage1", 27 );
	set( "natural_min_damage2", 9 );
	set( "natural_max_damage2", 25 );

	ob1 = new( "/d/noden/tamumu/obj/robe" );
	ob1->move( this_object() );
	equip_armor( ob1 );
}
