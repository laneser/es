#include "../hole.h"

inherit ARMOR;
void create()
{
	set_name( "Dragon Turban","火龍鬚頭巾" );
	add( "id", ({ "turban" }) );
	set_short( "火龍鬚頭巾" );
	set_long(@LONG
	火龍鬚所製成的頭巾，能靠龍的力量減少火的傷害。
LONG
		);
	set( "unit","條" );
	set( "weight",15 );
	set( "type","head" );
	set( "material","leather" );
	set( "armor_class",8 );
	set( "defense_bonus",4 );
	set( "special_defense",([ "fire":15 ]) );
	set( "value",({ 3570,"silver" }) );
}
