#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "padded robe", "軟甲護袍" );
	add( "id", ({ "robe" }) );
	set_short( "a padded robe", "軟甲護袍" );
	set_long(
		"You see a long robe with padded metal pieces. It looks light and\n"
		"protective.\n",
		"這是一件長型護袍，上面用金屬片鑲在肩部、前胸與後背，看起來相當輕便\n"
		"而且具不錯的保護效果。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "leather" );
	set( "armor_class", 15 );
	set( "defense_bonus", 5 );
	set( "special_defense", ([ "cold":4, "electric":-5 ]) );
	set( "weight", 80 );
	set( "value", ({ 1300, "silver" }) );
}
