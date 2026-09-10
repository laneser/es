#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "round cap", "圓頂小帽" );
	add( "id", ({ "cap" }) );
	set_short( "圓頂小帽" );
	set_long("這是一頂綢緞布面的圓頂小帽，看起來像是有錢人的帽子。\n");
	set( "unit", "頂" );
	set( "type", "head" );
	set( "material", "cloth" );
	set( "armor_class", 4 );
	set( "weight", 20 );
	set( "value", ({ 70, "silver" }) );
}
