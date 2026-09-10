#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "alloyed visor helm", "合金覆面頭盔" );
	add( "id", ({ "visor helm", "visor", "helm" }) );
	set_short( "an alloyed visor helm", "合金覆面頭盔" );
	set_long(
		"You see an alloyed visor helm. It looks pretty heavy and\n"
		"can supply good protection.\n",
		"這是一面用某種不知名合金打造的覆面頭盔，看起來相當重。\n"
	);
	set( "unit", "具" );
	set( "type", "head" );
	set( "material", "heavy_metal" );
	set( "armor_class", 6 );
	set( "weight", 80 );
	set( "value", ({ 580, "silver" }) );
}
