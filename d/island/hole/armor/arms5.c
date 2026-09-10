#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Fire Scale Arms","火麟護臂" );
	add( "id",({ "arms" }) );
	set_short( "火麟護臂" );
	set_long(@LONG
	這是一對臂環，每個臂環上都鑲著一片火麒麟
	的鱗片。
LONG
           );
	set( "unit","雙" );
	set( "weight",50 );
	set( "type","arms" );
	set( "material","leather" );
	set( "armor_class",5 );
	set( "defense_bonus",4 );
	set( "special_defense",([ "fire":25 ]) );
	set( "value",({ 570,"silver" }) );
//	set( "no_sale",1 );
}
