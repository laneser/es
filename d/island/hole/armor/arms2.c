#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Armbands","守衛識別臂環" );
	add( "id",({ "armbands" }) );
	set_short( "守衛識別臂環" );
	set_long(@LONG
	臂環。
LONG
           );
	set( "unit","雙" );
	set( "weight",8 );
	set( "type","arms" );
	set( "material","light_metal" );
	set( "defense_bonus",2 );
	set( "value",({ 570,"silver" }) );
}
