#include <mudlib.h>

inherit MONSTER;

void create()
{
	object obj;

	::create();
	set_level( 3 );
	set_name( "old gardener", "老園丁" );
	add( "id", ({ "gardener" }) );
	set_short( "老園丁" );
	set_long(
		"這位園丁的年紀已經很老了，但是他仍然辛勤地在修剪花木。\n"
	);
	set( "race", "centaur" );
	set( "gender", "male" );
	set_skill( "shortblade", 40 );
	set_skill( "parry", 30 );
	set( "alignment", 400 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage1", 2 );
	set( "natural_max_damage1", 5 );

	obj = new( "/d/noden/nodania/obj/scissors" );
	obj->move( this_object() );
	wield_weapon( obj );
}
