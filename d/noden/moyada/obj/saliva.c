#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
   set_name( "saliva of chocobo", "陸行鳥的口水" );
   add( "id", ({ "saliva", "water" }) );
   set_short( "陸行鳥的口水" );
	set_long(
           "這是陸行鳥的口水, 你可以試試把它喝下去。\n"
	);
	set_healing( 20 );
	set( "no_sale", 1 );
   set( "unit", "灘" );
	set( "weight", 20 );
	set( "value", ({ 80, "silver" }) );
	set( "medication", 20 );
	set( "effect_critical", 100 );
}
