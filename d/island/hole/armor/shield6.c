#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Fire Shield","灼熱盾" );
	add( "id", ({ "shield" }) );
	set_short( "灼熱盾" );
	set_long(@LONG
	能夠封閉火焰的盾。
LONG
		);
	set( "unit","面" );
	set( "weight",120 );
	set( "type","shield" );
	set( "material","light_metal" );
	set( "armor_class",8 );
	set( "defense_bonus",3 );
	set( "special_defense",([ "fire":30,"cold":-15 ]) );
	set( "value",({ 2150,"silver" }) );
}
