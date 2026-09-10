#include "../nodania.h"

inherit MONSTER;

void create()
{
	object key;

	::create();
	set_level(5);
	set_name("servant", "僕役");
	set_short("僕役");
	set_long(
		"一個看起來很普通的僕役，負責接待貴賓。\n"
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "natural_armor_class", 25 );
	set( "natural_weapon_class1", 10 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 8 );
	set( "alignment", 100 );

	key = new( NODANIA"obj/ivory_key" );
	key->move( this_object() );
}
