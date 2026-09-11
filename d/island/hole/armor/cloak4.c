#include "../hole.h"

inherit ARMOR;
void create()
{
	set_name( "Oath Cloak","誓言披風" );
	add( "id",({ "cloak" }) );
	set_short( "誓言披風" );
	set_long(@LONG
	發誓成為聖者時，做為信物贈與的禮物。
LONG
           );
	set( "unit","襲" );
	set( "weight",40 );
	set( "type","cloak" );
	set( "material","cloth" );
	set( "armor_class",6 );
	set( "defense_bonus",4 );
	set( "special_defense",([ "evil":20 ]) );
	set( "value",({ 1170,"silver" }) );
}
