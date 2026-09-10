#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "chaos ring", "渾沌戒" );
	add( "id", ({ "ring" }) );
	set_short( "渾沌戒" );
	set_long( 
@C_LONG
一個閃耀著淺紫色光芒的戒子，當你注視著它時，卻發現其內部一片深邃，
令你看不清楚。
C_LONG
	);
	set( "unit", "只" );
	set( "type", "finger" );
	set( "material", "element" );
	set( "defense_bonus", 7 );
	set( "special_defense", 
	     ([ "all":10 ]) );
	set( "weight", 5 );
	set( "no_sale", 1);
	set( "value", ({ 5000, "silver" }) );
}
