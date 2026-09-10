#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "stone axe", "石板斧" );
	add( "id", ({ "axe" }) );
   set_short( "石板斧" );
	set_long(
		"這是一把用堅硬的花崗岩鑿成的石板斧，綁著一根短木棍做斧柄。\n"
	);
	set( "unit", "把" );
	set( "weight", 100 );
	setup_weapon( "axe", 10, 5, 13 );
	set( "value", ({ 165, "silver" }) );
}
