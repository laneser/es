#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Armbands","戰神臂環" );
	add( "id",({ "armbands" }) );
	set_short( "戰神臂環" );
	set_long(@LONG
	這是戰神五種配備中的臂環。
LONG
           );
	set( "unit","雙" );
	set( "weight",10 );
	set( "type","arms" );
	set( "material","heavy_metal" );
	set( "armor_class",4 );
	set( "defense_bonus",4 );
	set( "value",({ 2100,"silver" }) );
//	set( "no_sale",1 );
}