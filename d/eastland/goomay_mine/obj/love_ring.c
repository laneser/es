#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "ring", "藍海情戒" );
	add( "id", ({ "ring","blue" }) );
	set_short( "love ring", "藍海情戒" );
	set_long(@C_LONG
一隻泛出藍色光芒的戒指，看起來似乎有點不尋常，不過對於戀愛中的情侶
倒不失為一個表示情意的信物。
C_LONG
	);
	set( "unit", "只" );
	set( "type", "finger" );
	set( "material", "element" );
	set( "defense_bonus", 6 );
	set( "special_defense", 
	     ([ "fire":2 ]) );      
	set( "weight", 5 );
	set( "value", ({ 2500, "silver" }) );
}
