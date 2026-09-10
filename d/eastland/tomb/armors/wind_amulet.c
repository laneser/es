#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wind amulet", "風之護符" );
	add( "id", ({ "amulet" }) );
	set_short( "風之護符" );
	set_long(
		"這是一張奇異的護符，閃耀著淺紫色的光芒，你可以感受到它充滿了能量。\n"
	);
	set( "unit", "面" );
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "defense_bonus", 5 );
	set( "special_defense",
	     ([ "evil":15, "divine": -10 ]) );
	set( "weight", 5 );
	set( "value", ({ 1100, "silver" }) );
}
