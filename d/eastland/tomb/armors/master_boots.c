#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "master boots", "天師靴" );
	add( "id", ({ "boots", }) );
	set_short( "天師靴" );
	set_long( 
@C_TOPIC
一雙據說是由龍虎山  張天師施術過的靴子，有著意想不到的功效\。
C_TOPIC
	);
	set( "unit", "雙" );
	set( "type", "feet" );
	set( "material", "cloth" );
	set( "armor_class", 8 );
	set( "defense_bonus", 2 );
	set( "special_defense", 
	     ([ "divine":15, "none":15 ]) );
	set( "weight", 20 );
	set( "no_sale", 1);
	set( "value", ({ 3700, "silver" }) );
}
