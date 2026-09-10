#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "thunder amulet", "雷之護符" );
	add( "id", ({ "amulet" }) );
	set_short( "雷之護符" );
	set_long(
		"這是一張奇異的護符，閃耀著青白色的光芒，你可以感受到它充滿了能量。\n"
	);
	set( "unit", "面" );
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "defense_bonus", 5 );
	set( "special_defense",
	     ([ "electric":15, "mental": -10 ]) );
	set( "weight", 5 );
	set( "value", ({ 1300, "silver" }) );
}
