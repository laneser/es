#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Death Cloak","死神披風" );
	add( "id",({ "cloak" }) );
	set_short( "死神披風" );
	set_long(@LONG
	這是傳說中會熄滅生命火焰的披風，只有死神
	才能擁有它。
LONG
           );
	set( "unit","件" );
	set( "weight",40 );
	set( "type","cloak" );
	set( "material","cloth" );
	set( "armor_class",5 );
	set( "defense_bonus",6 );
	set( "special_defense",([ "fire":25,"cold":10,"none":15 ]) );
	set( "value",({ 975,"silver" }) );
}
