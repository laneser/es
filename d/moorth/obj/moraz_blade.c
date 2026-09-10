#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "Moraz blade", "默雷茲長刀" );
	add( "id", ({ "blade", "sword" }) );
	set_short( "Moraz Blade", "默雷茲長刀" );
	set_long(
		"You see a long sword with a long crane. The sword is well balanced\n"
		"for those mastering usage of swords and lance.\n",
		"這是一把造型很像長槍的長刀，它的刀柄很長，並且改良過刀身的平衡，使得\n"
		"擅於使用長劍和槍型武器的人能十分快速地揮動這把刀。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 110 );
	set( "nosecond", 1 );
	set( "bleeding", 10 );
	set( "weapon_class", 33 );
	set( "min_damage", 13 );
	set( "max_damage", 30 );
	set( "value", ({ 1340, "silver" }) );
	set( "no_sale", 1 );
}
